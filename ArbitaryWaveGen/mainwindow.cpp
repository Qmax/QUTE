#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent,Qt::FramelessWindowHint),
        ui(new Ui::MainWindow)
{

    QPluginLoader loader1("libQmaxPTInterface.so", this);
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader1.instance());

    QPluginLoader loaderSPI("libSPIMemoryInterface.so", this);
    ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loaderSPI.instance());

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());

    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();

    QPluginLoader testing("libAppBckPsoc.so", this);
    testjig = qobject_cast<IPTAppBckPsocInterface*> (testing.instance());

    //_______________________________________________
    m_nAmplitude=1.0;
    m_nOffset=0.0;
    hwInterface=new HardwareInterface();
    hwInterface->Init();
    hwInterface->setHighImpedance(true);
    hwInterface->setAmplitude(m_nAmplitude);
    hwInterface->setFrequency(1000.0);
    hwInterface->setOffset(m_nOffset);
    hwInterface->setPhase(0);
    hwInterface->Drive(STOPDRIVE);
    //__________________________________________________

    m_nX.resize(4000);     m_nY.resize(4000);
    m_nX1.resize(4000);    m_nY1.resize(4000);
    m_nX2.resize(4000);    m_nY2.resize(4000);
    m_nX3.resize(4000);    m_nY3.resize(4000);
    m_nX4.resize(4000);    m_nY4.resize(4000);
    m_nX5.resize(4000);    m_nY5.resize(4000);
    m_nX6.resize(4000);    m_nY6.resize(4000);
    graphSelect=0;

    srand(QDateTime::currentDateTime().toTime_t());
    ui->setupUi(this);

    QPalette palette;
    QLinearGradient gradient(ui->frame_2->rect().topLeft(),ui->frame_2->rect().bottomLeft());
    gradient.setColorAt(0,	QColor(255,255,255));
    gradient.setColorAt(1,	QColor(218,219,255));
    palette.setBrush(QPalette::Background, QBrush(gradient));

    ui->customPlot->setBackground(QBrush(gradient));
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables | QCP::iMultiSelect | QCP::iSelectItems | QCP::iSelectOther);
    xAxisLower=-1;
    xAxisUpper=500;
    yAxisLower=-5;
    yAxisUpper=5;
    ui->customPlot->xAxis->setRange(xAxisLower, xAxisUpper);
    ui->customPlot->yAxis->setRange(yAxisLower, yAxisUpper);
    ui->customPlot->axisRect()->setupFullAxesBox();

    //  ui->customPlot->plotLayout()->insertRow(0);
    //  ui->customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->customPlot, "ARBITARY WAVEFORM GENERATOR"));

    ui->customPlot->xAxis->setLabel("x Axis");
    ui->customPlot->yAxis->setLabel("y Axis");
    ui->customPlot->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->legend->setSelectedFont(legendFont);
    ui->customPlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items


    // connect slot that ties some axis selections together (especially opposite axes):
    connect(ui->customPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    // connect slots that takes care that when an axis is selected, only that direction can be dragged and zoomed:
    connect(ui->customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(ui->customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));

    // make bottom and left axes transfer their ranges to top and right axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // connect some interaction slots:
    connect(ui->customPlot, SIGNAL(titleDoubleClick(QMouseEvent*,QCPPlotTitle*)), this, SLOT(titleDoubleClick(QMouseEvent*,QCPPlotTitle*)));
    connect(ui->customPlot, SIGNAL(axisDoubleClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)));
    connect(ui->customPlot, SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));

    // connect slot that shows a message in the status bar when a graph is clicked:
    connect(ui->customPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*)));

    // setup policy and connect slot for context menu popup:
    ui->customPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->customPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
    maxList.insert(0,20.0);             minList.insert(0,0.01);
    maxList.insert(1,5000000.0);        minList.insert(1,0.01);
    maxList.insert(2,360.0);            minList.insert(2,0.0);
    maxList.insert(3,5.0);              minList.insert(3,-5.0);

    callType.insert(0,'V');             callType.insert(1,'X');
    callType.insert(2,'X');             callType.insert(3,'v');

    setGeometry(0,33,800,567);

    label[0]=new QmaxLabel(0,this);
    label[0]->setGeometry(ui->label_Amplitude->geometry());
    label[0]->setText(ui->label_Amplitude->text());
    label[0]->setGeometry(20,500,120,17);
    ui->label_Amplitude->setVisible(false);
    lineEdit[0]=new QmaxLineEdit(0,this);
    lineEdit[0]->setGeometry(18,517,124,30);
    connect(lineEdit[0],SIGNAL(focussed(bool)),label[0],SLOT(setlabelFocus(bool)));
    connect(lineEdit[0],SIGNAL(focussed(int)),this,SLOT(callLineEditInput(int)));
    lineEdit[0]->setText("1Vpp");

    label[1]=new QmaxLabel(1,this);
    label[1]->setGeometry(ui->label_Frequency->geometry());
    label[1]->setText(ui->label_Frequency->text());
    label[1]->setGeometry(160,500,120,17);
    ui->label_Frequency->setVisible(false);
    lineEdit[1]=new QmaxLineEdit(1,this);
    lineEdit[1]->setGeometry(158,517,124,30);
    connect(lineEdit[1],SIGNAL(focussed(bool)),label[1],SLOT(setlabelFocus(bool)));
    connect(lineEdit[1],SIGNAL(focussed(int)),this,SLOT(callLineEditInput(int)));
    lineEdit[1]->setText("100");

    label[2]=new QmaxLabel(2,this);
    label[2]->setGeometry(ui->label_Phase->geometry());
    label[2]->setText(ui->label_Phase->text());
    label[2]->setGeometry(300,500,120,17);
    ui->label_Phase->setVisible(false);
    lineEdit[2]=new QmaxLineEdit(2,this);
    lineEdit[2]->setGeometry(300,517,124,30);
    connect(lineEdit[2],SIGNAL(focussed(bool)),label[2],SLOT(setlabelFocus(bool)));
    connect(lineEdit[2],SIGNAL(focussed(int)),this,SLOT(callLineEditInput(int)));
    lineEdit[2]->setText("1");

    label[3]=new QmaxLabel(3,this);
    label[3]->setGeometry(ui->label_Offset->geometry());
    label[3]->setText(ui->label_Offset->text());
    label[3]->setGeometry(440,500,120,17);
    ui->label_Offset->setVisible(false);
    lineEdit[3]=new QmaxLineEdit(3,this);
    lineEdit[3]->setGeometry(437,517,124,30);
    connect(lineEdit[3],SIGNAL(focussed(bool)),label[3],SLOT(setlabelFocus(bool)));
    connect(lineEdit[3],SIGNAL(focussed(int)),this,SLOT(callLineEditInput(int)));
    lineEdit[3]->setText("0V");

    m_nCycles =1;
    m_nSamples=100;
    m_nCount=1;
    rescaleAxis=false;
    m_bUnipolar=false;
    graphSelect=prevGraphSelect=0;
    m_nVRef=1.0;

    m_nWaveSamples=1;
    m_nWaveStartTick=0;
    m_nWaveStopTick=1;
    m_nWaveDutyCycle=0;

    m_nTotalSamples=100;
    emit SendTotalSamples(m_nTotalSamples);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openWaveDataWindow(){
    m_objWaveData=new WaveData(graphSelect,this);
    m_objWaveData->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QPropertyAnimation *animation = new QPropertyAnimation(m_objWaveData, "geometry");
    animation->setStartValue(QRect(250, 350, 240, 50));
    animation->setEndValue(QRect(((800/2) - (240/2)), ((600/2) - (250/2)), 240, 250));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(300);
    animation->start();
    m_objWaveData->exec();
    qDebug()<<"Samples:"<<m_nWaveSamples<<"Start Tick:"<<m_nWaveStartTick<<"Stop Tick:"<<m_nWaveStopTick<<"DutyCycle:"<<m_nWaveDutyCycle;
}
void MainWindow::RxSamples(int data){m_nWaveSamples=data;qDebug()<<"Rxd m_nWaveSamples :"<<m_nWaveSamples;}
void MainWindow::RxStartTick(int data){m_nWaveStartTick=data;qDebug()<<"Rxd m_nWaveStartTick :"<<m_nWaveStartTick;}
void MainWindow::RxStopTick(int data){m_nWaveStopTick=data;qDebug()<<"Rxd m_nWaveStopTick :"<<m_nWaveStopTick;}
void MainWindow::RxDutyCycle(int data){m_nWaveDutyCycle=data;qDebug()<<"Rxd m_nWaveDutyCycle :"<<m_nWaveDutyCycle;}

void MainWindow::customEvent(QEvent *e) {


    if (e->type() == ((QEvent::Type) 5678)) {
        if(m_nPTKeyCode==1)      {  qDebug()<<("\nMENU"     );   }
        else if(m_nPTKeyCode==2) {  qDebug()<<("\nESC"      );   }
        else if(m_nPTKeyCode==3) {  qDebug()<<("\nNULL"     );   }
        else if(m_nPTKeyCode==4) {  qDebug()<<("\nF1"       );   }
        else if(m_nPTKeyCode==5) {  qDebug()<<("\nF2"       );   }
        else if(m_nPTKeyCode==6) {  qDebug()<<("\nF3"       );   }
        else if(m_nPTKeyCode==7) {  qDebug()<<("\nF4"       );   }
        else if(m_nPTKeyCode==8) {  qDebug()<<("\nF5"       );   }
        else if(m_nPTKeyCode==9) {  qDebug()<<("\nUP"       );   }
        else if(m_nPTKeyCode==10){  qDebug()<<("\nDOWN"     );   }
        else if(m_nPTKeyCode==11){  qDebug()<<("\nRIGHT"    );   }
        else if(m_nPTKeyCode==12){  qDebug()<<("\nLEFT"     );   }
        else if(m_nPTKeyCode==13){  qDebug()<<("\nENTER"    );   }
        else if(m_nPTKeyCode==14){  qDebug()<<("\nSETUP"    );   }
        else if(m_nPTKeyCode==15){  qDebug()<<("\nDEFAULT"  );   }
        else if(m_nPTKeyCode==16){  qDebug()<<("\nTOUCH"    );   }
        else if(m_nPTKeyCode==17){  qDebug()<<("\nFILE"     );   }
        else if(m_nPTKeyCode==18){  qDebug()<<("\nSCALE"    );   }
        else if(m_nPTKeyCode==19){  qDebug()<<("\nRUN/STOP" );   }
    }

    QEvent(e->type());
}
void MainWindow::titleDoubleClick(QMouseEvent* event, QCPPlotTitle* title)
{
    Q_UNUSED(event)
    // Set the plot title by double clicking on it
    bool ok;
    QString newTitle = QInputDialog::getText(this, "QCustomPlot example", "New plot title:", QLineEdit::Normal, title->text(), &ok);
    if (ok)
    {
        title->setText(newTitle);
        ui->customPlot->replot();
    }
}

void MainWindow::axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part)
{
    // Set an axis label by double clicking on it
    if (part == QCPAxis::spAxisLabel) // only react when the actual axis label is clicked, not tick label or axis backbone
    {
        bool ok;
        QString newLabel = QInputDialog::getText(this, "QCustomPlot example", "New axis label:", QLineEdit::Normal, axis->label(), &ok);
        if (ok)
        {
            axis->setLabel(newLabel);
            ui->customPlot->replot();
        }
    }
}

void MainWindow::legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item)
{
    // Rename a graph by double clicking on its legend item
    Q_UNUSED(legend)
    if (item) // only react if item was clicked (user could have clicked on border padding of legend where there is no item, then item is 0)
    {
        QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item);
        bool ok;
        QString newName = QInputDialog::getText(this, "QCustomPlot example", "New graph name:", QLineEdit::Normal, plItem->plottable()->name(), &ok);
        if (ok)
        {
            plItem->plottable()->setName(newName);
            ui->customPlot->replot();
        }
    }
}

void MainWindow::selectionChanged()
{
    /*
   normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
   the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
   and the axis base line together. However, the axis label shall be selectable individually.

   The selection state of the left and right axes shall be synchronized as well as the state of the
   bottom and top axes.

   Further, we want to synchronize the selection of the graphs with the selection state of the respective
   legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
   or on its legend item.
	 */

    // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
        ui->customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        ui->customPlot->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        ui->customPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }
    // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
        ui->customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->customPlot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        ui->customPlot->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        ui->customPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }

    // synchronize selection of graphs with selection of corresponding legend items:
    for (int i=0; i<ui->customPlot->graphCount(); ++i)
    {
        QCPGraph *graph = ui->customPlot->graph(i);
        QCPPlottableLegendItem *item = ui->customPlot->legend->itemWithPlottable(graph);
        if (item->selected() || graph->selected())
        {
            item->setSelected(true);
            graph->setSelected(true);
        }
    }
}

void MainWindow::mousePress()
{
    // if an axis is selected, only allow the direction of that axis to be dragged
    // if no axis is selected, both directions may be dragged

    if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->xAxis->orientation());
    else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->yAxis->orientation());
    else
        ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void MainWindow::mouseWheel()
{
    // if an axis is selected, only allow the direction of that axis to be zoomed
    // if no axis is selected, both directions may be zoomed

    if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->xAxis->orientation());
    else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->yAxis->orientation());
    else
        ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}
void MainWindow::clearGraphData(){
    for(int i=0;i<1000;i++){
        if(graphSelect==0){            m_nX[i]=0;         m_nY[i]=0;         }
        if(graphSelect==1){            m_nX1[i]=0;        m_nY1[i]=0;        }
        if(graphSelect==2){            m_nX2[i]=0;        m_nY2[i]=0;        }
        if(graphSelect==3){            m_nX3[i]=0;        m_nY3[i]=0;        }
        if(graphSelect==4){            m_nX4[i]=0;        m_nY4[i]=0;        }
        if(graphSelect==5){            m_nX5[i]=0;        m_nY5[i]=0;        }
        if(graphSelect==6){            m_nX6[i]=0;        m_nY6[i]=0;        }
    }
}

/*void MainWindow::addSineGraph(){
	prevGraphSelect=graphSelect;
	graphSelect=2;
    // generate data:
    clearGraphData();
    for (int l_nIndex=0; l_nIndex<(m_nSamples*m_nCycles); ++l_nIndex)
    {
        m_nX2[l_nIndex] = l_nIndex;
        m_nY2[l_nIndex]=1*sin(l_nIndex/1.0);
        if(graphSelect!=prevGraphSelect){
        	if(l_nIndex>m_nCount)
        		m_nCount = l_nIndex;
        }else{
        	m_nCount = l_nIndex;
        }
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("Sine-%1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX2, m_nY2);
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(2);
    ui->customPlot->graph()->setPen(graphPen);
    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();

    for(int i=0;i<(m_nSamples*m_nCycles);i++){
        m_nX[i]=m_nX2[i];
        m_nY[i]=m_nY2[i];
    }
}*/
void MainWindow::addSineGraph(){
    prevGraphSelect=graphSelect;
    graphSelect=2;
    clearGraphData();
    openWaveDataWindow();
    //************************************************************************
    double l_nYPoint =0.0,l_nDegree =0.0,l_nXPoint =0.0;
    unsigned int l_nSampleIndex=0,l_nIndex =0,l_nSamples=0,l_nRemainder =0,l_nTemp=0;

    l_nSamples = m_nWaveSamples / m_nCycles;
    l_nRemainder = (m_nWaveSamples%(int)m_nCycles)/l_nSamples;
    l_nTemp = l_nSamples;

    double l_nPhaseAngle=0.0;
    l_nPhaseAngle = (l_nDegree*3.14) / 180.0;

    double l_nAmplitude = 1.0*m_nVRef;
    double l_nTempYPoint=0.0;
    double l_nYPoint1 =0.0;
    double l_nTempAmp =0.0;

    while(l_nSampleIndex < (m_nCycles+l_nRemainder))
    {
        for(;l_nIndex<m_nWaveSamples;l_nIndex++)
        {
            l_nTempYPoint = l_nAmplitude*sin(l_nPhaseAngle);
            l_nYPoint = l_nTempYPoint;
            l_nYPoint1 = l_nTempAmp*sin(l_nPhaseAngle);
            m_nY2[l_nIndex] = l_nYPoint;
            l_nPhaseAngle = (l_nPhaseAngle +(2*3.14) / (m_nWaveSamples/m_nCycles));
            m_nX2[l_nIndex]=l_nIndex;
            if(l_nPhaseAngle > (2*3.14))
                l_nPhaseAngle = l_nPhaseAngle - (2*3.14);
            if(graphSelect!=prevGraphSelect){
                if(l_nIndex>m_nCount)
                    m_nCount = l_nIndex;
            }else{
                m_nCount = l_nIndex;
            }
        }
        l_nSamples += l_nTemp;
        l_nSampleIndex++;
    }

    //************************************************************************
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("Sine-%1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX2, m_nY2);
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(2);
    ui->customPlot->graph()->setPen(graphPen);
    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();

    for(int i=0;i<m_nWaveSamples;i++){
        m_nX[i]=m_nX2[i];
        m_nY[i]=m_nY2[i];
    }
}
void MainWindow::addSawtoothGraph(){
    prevGraphSelect=graphSelect;
    graphSelect=5;
    clearGraphData();
    openWaveDataWindow();

    double l_nYPoint =0.0,l_nDegree =0;
    unsigned int l_nSampleIndex=0,l_nIndex =0,l_nSamples=0,l_nTemp=0,l_nRemainder =0;
    l_nSamples = m_nWaveSamples / m_nCycles;
    l_nRemainder = (m_nWaveSamples%(int)m_nCycles)/l_nSamples;
    double l_nPhaseAngle=0.0;
    l_nPhaseAngle = (l_nDegree*3.14) / 180.0;
    double l_nAmplitude = 1.0*m_nVRef;
    double l_nTempYPoint=0.0;
    double l_nTempAmp =1.0;

    while(l_nSampleIndex < (m_nCycles+l_nRemainder))
    {
         for(;l_nIndex<m_nWaveSamples;l_nIndex++)
        {
            l_nTempYPoint =(l_nAmplitude) - (l_nAmplitude/3.14) * l_nPhaseAngle;
            m_nY5[l_nIndex] = ((l_nTempAmp) - (l_nTempAmp/3.14) * l_nPhaseAngle);
            if( false == true)
                l_nYPoint = l_nYPoint + 1.0;

            l_nPhaseAngle = (l_nPhaseAngle +sin((2*3.14) / (m_nWaveSamples/m_nCycles)));
            m_nX5[l_nIndex] = l_nIndex;
            if(l_nPhaseAngle > (2*3.14))
                l_nPhaseAngle = l_nPhaseAngle - (2*3.14);

            if(graphSelect!=prevGraphSelect){
            	if(l_nIndex>m_nCount)
                    m_nCount = l_nIndex;
            }else{
            	m_nCount = l_nIndex;
            }

        }
        l_nSamples -= l_nTemp;
        l_nSampleIndex++;

    }
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("Sawtooth-%1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX5, m_nY5);
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    //    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(2);
    ui->customPlot->graph()->setPen(graphPen);
    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();

    for(int i=0;i<m_nWaveSamples;i++){
        m_nX[i]=m_nX5[i];
        m_nY[i]=m_nY5[i];
    }
}

void MainWindow::addPulseGraph(){
    prevGraphSelect=graphSelect;
    graphSelect=6;
    clearGraphData();
    openWaveDataWindow();

    double l_nYPoint =0.0,l_nDegree =0,l_nXPoint =0.0;
    double l_nDutyCycle = double(m_nWaveDutyCycle);
    l_nDutyCycle = l_nDutyCycle /100;
    double l_nConstValue = (2.0*3.14) *(float)(l_nDutyCycle);
    unsigned int l_nSampleIndex=0,l_nIndex =0,l_nSamples=0,l_nRemainder =0,l_nTemp=0;

    l_nSamples = m_nWaveSamples / m_nCycles;
    l_nRemainder = (m_nWaveSamples%(int)m_nCycles)/l_nSamples;
    l_nTemp = l_nSamples;
    double l_nPhaseAngle=0.0;
    l_nPhaseAngle = (l_nDegree*3.14) / 180.0;
    double l_nAmplitude = 1*m_nVRef;
    double l_nTempYPoint=0.0;
    double l_nTempAmp =1.0;

    while(l_nSampleIndex < (m_nCycles+l_nRemainder))
    {
        for(;l_nIndex<m_nWaveSamples;l_nIndex++)
        {

            if(l_nPhaseAngle < l_nConstValue){
                l_nTempYPoint = -l_nAmplitude;
                m_nY6[l_nIndex] = l_nTempAmp;

            }
            else{
                l_nTempYPoint = (l_nAmplitude);
                m_nY6[l_nIndex] = -l_nTempAmp;
            }

            l_nPhaseAngle = (l_nPhaseAngle +(2*3.14) / (m_nWaveSamples/m_nCycles));
            m_nX6[l_nIndex] = l_nIndex;
            if(l_nPhaseAngle > (2*3.14) )
                l_nPhaseAngle = l_nPhaseAngle - (2*3.14);
            if(graphSelect!=prevGraphSelect){
            	if(l_nIndex>m_nCount)
                    m_nCount = l_nIndex;
            }else{
            	m_nCount = l_nIndex;
            }
        }
        l_nSamples += l_nTemp;
        l_nSampleIndex++;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("Pulse-%1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX6, m_nY6);
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    //    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(2);
    ui->customPlot->graph()->setPen(graphPen);
    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();

    for(int i=0;i<m_nWaveSamples;i++){
        m_nX[i]=m_nX6[i];
        m_nY[i]=m_nY6[i];
    }
}

void MainWindow::addSquareGraph(){
    prevGraphSelect=graphSelect;
    graphSelect=3;
    clearGraphData();
    openWaveDataWindow();

    double l_nYPoint =0.0,l_nDegree =0,l_nXPoint =0.0;
    double l_nConstValue = (2.0*3.14) *(float)(0.5);
    unsigned int l_nSampleIndex=0;
    unsigned int l_nIndex =0;
    unsigned int l_nSamples=0;
    unsigned int l_nRemainder =0;
    unsigned int l_nTemp=0;

    l_nSamples = m_nWaveSamples / m_nCycles;
    l_nRemainder = (m_nWaveSamples%m_nCycles)/m_nWaveSamples;
    l_nTemp = l_nSamples;
    double l_nPhaseAngle=0.0;
    l_nPhaseAngle = (l_nDegree*3.14) / 180.0;
    double l_nAmplitude = 1*m_nVRef;
    double l_nTempYPoint=0.0;
    double l_nTempAmp =1.0;

    while(l_nSampleIndex < (m_nCycles+l_nRemainder))
    {
        for(;l_nIndex<m_nWaveSamples;l_nIndex++)
        {

            if(l_nPhaseAngle < l_nConstValue){
                l_nTempYPoint = l_nAmplitude;
                m_nY3[l_nIndex]  = l_nTempAmp;

            }
            else{
                l_nTempYPoint = -(l_nAmplitude);
                m_nY3[l_nIndex]  = -l_nTempAmp;
            }

            l_nPhaseAngle = (l_nPhaseAngle +(2*3.14) / (m_nWaveSamples/m_nCycles));
            m_nX3[l_nIndex] = l_nIndex;
            //printf("Phase Angle : %f XPoint :%f YPoint : %f\n",l_nPhaseAngle,l_nXPoint,l_nYPoint);
            if(l_nPhaseAngle > (2*3.14) )
                l_nPhaseAngle = l_nPhaseAngle - (2*3.14);
            if(graphSelect!=prevGraphSelect){
            	if(l_nIndex>m_nCount)
                    m_nCount = l_nIndex;
            }else{
            	m_nCount = l_nIndex;
            }
        }
        l_nSamples += l_nTemp;
        l_nSampleIndex++;
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("Square-%1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX3, m_nY3);
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    //    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(2);
    ui->customPlot->graph()->setPen(graphPen);
    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();

    for(int i=0;i<m_nWaveSamples;i++){
        m_nX[i]=m_nX3[i];
        m_nY[i]=m_nY3[i];
    }
}

void MainWindow::addTriangleGraph(){
    prevGraphSelect=graphSelect;
    graphSelect=4;
    clearGraphData();
    openWaveDataWindow();

    double l_nYPoint =0.0,l_nDegree =0,l_nXPoint =0.0;

    unsigned int l_nSampleIndex=0,l_nIndex =0,l_nSamples=0,l_nRemainder =0,l_nTemp=0;

    l_nSamples = m_nWaveSamples / m_nCycles;
    l_nRemainder = (m_nWaveSamples%(int)m_nCycles)/l_nSamples;

    double l_nPhaseAngle=0.0;
    l_nPhaseAngle = (l_nDegree*3.14) / 180.0;
    double l_nAmplitude = 1*m_nVRef;
    double l_nTempYPoint=0.0;
    double l_nTempAmp =1.0;

    while(l_nSampleIndex < (m_nWaveSamples+l_nRemainder))
    {

        for(l_nIndex=0;l_nIndex<m_nWaveSamples;l_nIndex++)
        {
            if(l_nPhaseAngle < 3.14)
            {
                l_nTempYPoint = -(l_nAmplitude) + (2*l_nAmplitude/3.14) * l_nPhaseAngle;
                m_nY4[l_nIndex]= -(l_nTempAmp) + (2*l_nTempAmp/3.14) * l_nPhaseAngle;
            }
            else
            {
                l_nTempYPoint = 3*(l_nAmplitude) - (2*l_nAmplitude/3.14) * l_nPhaseAngle;
                m_nY4[l_nIndex] = 3*(l_nTempAmp) - (2*l_nTempAmp/3.14) * l_nPhaseAngle;
            }

            l_nPhaseAngle = (l_nPhaseAngle +(2*3.14) / (m_nWaveSamples/m_nCycles));
            m_nX4[l_nIndex] = l_nIndex;
            if(l_nPhaseAngle > (2*3.14))
                l_nPhaseAngle = l_nPhaseAngle - (2*3.14);
            if(graphSelect!=prevGraphSelect){
            	if(l_nIndex>m_nCount)
                    m_nCount = l_nIndex;
            }else{
            	m_nCount = l_nIndex;
            }
        }
        l_nSamples += l_nTemp;
        l_nSampleIndex++;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("Triangle-%1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX4, m_nY4);
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    //    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(2);
    ui->customPlot->graph()->setPen(graphPen);
    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();

    for(int i=0;i<m_nWaveSamples;i++){
        m_nX[i]=m_nX4[i];
        m_nY[i]=m_nY4[i];
    }
}

void MainWindow::addRandomGraph(){
    prevGraphSelect=graphSelect;
    graphSelect=1;
    clearGraphData();
    openWaveDataWindow();

    double xScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double yScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double xOffset = (rand()/(double)RAND_MAX - 0.5)*4;
    double yOffset = (rand()/(double)RAND_MAX - 0.5)*5;
    double r1 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r2 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r3 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r4 = (rand()/(double)RAND_MAX - 0.5)*2;
    QVector<double> x(m_nWaveSamples), y(m_nWaveSamples);
    for (int l_nIndex=0; l_nIndex<m_nWaveSamples; l_nIndex++)
    {
        m_nX1[l_nIndex] = 1*(l_nIndex/(double)m_nWaveSamples-0.5)*10.0*xScale + xOffset;
        m_nY1[l_nIndex] = 1*(sin(x[l_nIndex]*r1*5)*sin(cos(x[l_nIndex]*r2)*r4*3)+r3*cos(sin(x[l_nIndex])*r4*2))*yScale + yOffset;
        if(graphSelect!=prevGraphSelect){
            if(l_nIndex>m_nCount)
                m_nCount = l_nIndex;
        }else{
            m_nCount = l_nIndex;
        }
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("New graph %1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX1, m_nY1);
    ui->customPlot->graph()->setLineStyle((QCPGraph::LineStyle)(rand()%5+1));
    //  if (rand()%100 > 75)
    //    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(rand()%9+1)));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(rand()/(double)RAND_MAX*2+1);
    ui->customPlot->graph()->setPen(graphPen);
    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();

    for(int i=0;i<m_nWaveSamples;i++){
        m_nX[i]=m_nX1[i];
        m_nY[i]=m_nY1[i];
    }
}

void MainWindow::removeSelectedGraph()
{
    if (ui->customPlot->selectedGraphs().size() > 0)
    {
        ui->customPlot->removeGraph(ui->customPlot->selectedGraphs().first());
        ui->customPlot->replot();
    }
}

void MainWindow::removeAllGraphs()
{
    graphSelect=0;clearGraphData();
    graphSelect=1;clearGraphData();
    graphSelect=2;clearGraphData();
    graphSelect=3;clearGraphData();
    graphSelect=4;clearGraphData();
    graphSelect=5;clearGraphData();
    graphSelect=6;clearGraphData();

    ui->customPlot->clearGraphs();
    ui->customPlot->replot();
}

void MainWindow::contextMenuRequest(QPoint pos)
{
    /*  QMenu *menu = new QMenu(this);
  menu->setAttribute(Qt::WA_DeleteOnClose);

  if (ui->customPlot->legend->selectTest(pos, false) >= 0) // context menu on legend requested
  {
    menu->addAction("Move to top left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
    menu->addAction("Move to top center", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
    menu->addAction("Move to top right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
    menu->addAction("Move to bottom right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
    menu->addAction("Move to bottom left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
  } else  // general context menu on graphs requested
  {
    menu->addAction("Add random graph", this, SLOT(addRandomGraph()));
    menu->addAction("Add Sine Wave",this,SLOT(addSineGraph()));
    menu->addAction("Add Square Wave",this,SLOT(addSquareGraph()));
    menu->addAction("Add Triangle Wave",this,SLOT(addTriangleGraph()));
    menu->addAction("Add Sawtooth Wave",this,SLOT(addSawtoothGraph()));
    menu->addAction("Add Pulse Wave",this,SLOT(addPulseGraph()));
    if (ui->customPlot->selectedGraphs().size() > 0)
      menu->addAction("Remove selected graph", this, SLOT(removeSelectedGraph()));
    if (ui->customPlot->graphCount() > 0)
      menu->addAction("Remove all graphs", this, SLOT(removeAllGraphs()));
  }

  menu->popup(ui->customPlot->mapToGlobal(pos));*/
}

void MainWindow::moveLegend()
{
    if (QAction* contextAction = qobject_cast<QAction*>(sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
    {
        bool ok;
        int dataInt = contextAction->data().toInt(&ok);
        if (ok)
        {
            ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
            ui->customPlot->replot();
        }
    }
}

void MainWindow::graphClicked(QCPAbstractPlottable *plottable)
{
    ui->statusBar->showMessage(QString("Clicked on graph '%1'.").arg(plottable->name()), 1000);
}


void MainWindow::MergeAll()
{
    prevGraphSelect=graphSelect;
    graphSelect=0;
    //    clearGraphData();
    //    for(int i=0;i<100;i++){
    //        m_nX[i]=i;
    //
    //        if((m_nY1[i]>m_nY2[i])&&(m_nY1[i]>m_nY3[i])&&(m_nY1[i]>m_nY4[i])&&(m_nY1[i]>m_nY5[i])&&(m_nY1[i]>m_nY6[i]))
    //            m_nY[i]=m_nY1[i];
    //        else if((m_nY2[i]>m_nY1[i])&&(m_nY2[i]>m_nY3[i])&&(m_nY2[i]>m_nY4[i])&&(m_nY2[i]>m_nY5[i])&&(m_nY2[i]>m_nY6[i]))
    //            m_nY[i]=m_nY2[i];
    //        else if((m_nY3[i]>m_nY2[i])&&(m_nY3[i]>m_nY1[i])&&(m_nY3[i]>m_nY4[i])&&(m_nY3[i]>m_nY5[i])&&(m_nY3[i]>m_nY6[i]))
    //            m_nY[i]=m_nY3[i];
    //        else if((m_nY4[i]>m_nY2[i])&&(m_nY4[i]>m_nY3[i])&&(m_nY4[i]>m_nY1[i])&&(m_nY4[i]>m_nY5[i])&&(m_nY4[i]>m_nY6[i]))
    //            m_nY[i]=m_nY4[i];
    //        else if((m_nY5[i]>m_nY2[i])&&(m_nY5[i]>m_nY3[i])&&(m_nY5[i]>m_nY4[i])&&(m_nY5[i]>m_nY1[i])&&(m_nY5[i]>m_nY6[i]))
    //            m_nY[i]=m_nY5[i];
    //        else
    //            m_nY[i]=m_nY6[i];
    //    }
    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("Merged").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(m_nX, m_nY);
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    //    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar));
    QPen graphPen;
    graphPen.setColor(QColor(22,68,153));
    graphPen.setWidthF(2);
    ui->customPlot->graph()->setPen(graphPen);
    //    //ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->replot();
    //    for(int i=0;i<100;i++){
    //        if(m_nX[i]==0 && m_nX1[i]==0 && m_nX2[i]==0 && m_nX3[i]==0 && m_nX4[i]==0 && m_nX5[i]==0 && m_nX6[i]==0 && m_nY[i]==0 && m_nY1[i]==0 && m_nY2[i]==0 && m_nY3[i]==0 && m_nY4[i]==0 && m_nY5[i]==0 && m_nY6[i]==0)
    //            ui->customPlot->clearGraphs();
    //
    //       }
}

void MainWindow::on_actionSine_triggered()
{
    addSineGraph();
}

void MainWindow::on_actionSquare_triggered()
{
    addSquareGraph();
}

void MainWindow::on_actionTriangle_triggered()
{
    addTriangleGraph();
}

void MainWindow::on_actionSAwtooth_triggered()
{
    addSawtoothGraph();
}

void MainWindow::on_actionPulse_triggered()
{
    addPulseGraph();
}

void MainWindow::on_actionMerge_All_triggered()
{
    MergeAll();
}

void MainWindow::on_actionRandom_triggered()
{
    addRandomGraph();
}

void MainWindow::on_actionRemove_All_triggered()
{
    removeAllGraphs();
}

void MainWindow::on_actionRemove_Selected_triggered()
{
    removeSelectedGraph();
}

void MainWindow::on_actionZoomin_triggered()
{
}

void MainWindow::on_actionZoom_Out_triggered()
{
}

void MainWindow::on_butMergeAll_clicked(){
    MergeAll();
}

void MainWindow::on_butRandom_clicked(){
    addRandomGraph();

}

void MainWindow::on_butPulse_clicked(){
    addPulseGraph();
}

void MainWindow::on_butSawtooth_clicked(){
    addSawtoothGraph();
}

void MainWindow::on_butTriangle_clicked(){
    addTriangleGraph();
}

void MainWindow::on_butSquare_clicked(){
    addSquareGraph();
}

void MainWindow::on_butSine_clicked(){
    addSineGraph();
}

void MainWindow::on_butRemoveSelected_clicked(){
    removeSelectedGraph();
}

void MainWindow::on_butRemoveAll_clicked(){
    removeAllGraphs();
}

void MainWindow::on_butExit_clicked()
{
    this->close();
}



void MainWindow::on_butZoomOut_clicked()
{
    xAxisLower=-1;
    if(xAxisLower!=0)xAxisUpper=xAxisUpper-1;
    yAxisLower=yAxisLower+2;
    if(yAxisUpper!=0)yAxisUpper=yAxisUpper-2;

    ui->customPlot->xAxis->setRangeLower(xAxisLower);
    ui->customPlot->xAxis->setRangeUpper(xAxisUpper);
    ui->customPlot->yAxis->setRangeLower(yAxisLower);
    ui->customPlot->yAxis->setRangeUpper(yAxisUpper);

    ui->customPlot->replot();
}

void MainWindow::on_butZoomIn_clicked()
{
    //    xAxisLower=-1;
    //    xAxisUpper=xAxisUpper+1;
    //    if(yAxisLower!=0)yAxisLower=yAxisLower-2;
    //    yAxisUpper=yAxisUpper+2;
    //
    //    ui->customPlot->xAxis->setRangeLower(xAxisLower);
    //    ui->customPlot->xAxis->setRangeUpper(xAxisUpper);
    //    ui->customPlot->yAxis->setRangeLower(yAxisLower);
    //    ui->customPlot->yAxis->setRangeUpper(yAxisUpper);
    //
    //    ui->customPlot->replot();
    ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->yAxis->orientation());
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::receiveValue(double pValue){
    switch(m_nLineEditIndex){
    case 0:
        m_nAmplitude = pValue;
    	hwInterface->setAmplitude(m_nAmplitude);
        break;
    case 1:
        m_nTotalSamples= (int) pValue;
        emit SendTotalSamples(m_nTotalSamples);
        break;
    case 2:
        m_nCycles = (int) pValue;
        break;
    case 3:
    	m_nOffset = pValue;
    	hwInterface->setOffset(m_nOffset);
        break;
    }
    ui->customPlot->replot();
}
void MainWindow::receiveValue(QString pValue){
    lineEdit[m_nLineEditIndex]->setText(pValue);
}
void MainWindow::receiveValue(uint pValue){

}
void MainWindow::callLineEditInput(int leFocussed){
    QWidget *m_w;
    m_nLineEditIndex=leFocussed;
    m_w = INumberPanel->getNumKBPanelIncDec(1,1,callType.value(leFocussed), maxList.value(leFocussed), minList.value(leFocussed),this);
    m_w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    m_w->setStyleSheet("color: #333;background: qradialgradient(cx: 0.3, cy: -0.4,fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #fff, stop: 1 #888);");
    m_w->show();
}

void MainWindow::on_butStart_clicked()
{
    GenerateHexPattern();
    usleep(1000);
    //	IAppCard->basicTimeUnit(999);
    //	IAppCard->basicDuration(0);
    //    IAppCard->setStartStop(1,1);
    //    IAppCard->setDrivePeriod(100);
    //    IAppCard->setDrivePatternCount(true, 0);
    //    IAppCard->setDDSWaveSelect(RAM_DATA);
    //    IAppCard->writeRegister(0x0000,0x86);
    //
    //	loadRAM();
    //
    //    IAppCard->writeRegister(0,0x82);
    //    IAppCard->writeRegister(0x63,0x84);
    //    IAppCard->writeRegister(0x0003,0x86);
    IAppCard->stopDrive();
    usleep(1000);

    IAppCard->writeRegister(0x0999,0x04);      //BTU
    usleep(1000);

    IAppCard->writeRegister(0x0000,0x06);      //BDR
    usleep(1000);

    IAppCard->writeRegister(0x0100,0x1C);      //Start/Stop Delay
    usleep(1000);

    IAppCard->writeRegister(0xc34f,0x18);      //WDP
    usleep(1000);

    IAppCard->writeRegister(0x0000,0x1A);      //Pattern Repeat
    usleep(1000);

    IAppCard->writeRegister(0x0001,0x34);
    usleep(1000);

    IAppCard->writeRegister(0x0000,0x82);       //Start Addr
    usleep(1000);

    IAppCard->writeRegister(m_nCount,0x84);     //End Addr
    usleep(1000);

    IAppCard->writeRegister(0x0000,0x86);
    usleep(1000);

    loadRAM();

    IAppCard->writeRegister(0x0003,0x86);
    usleep(1000);

    IAppCard->writeRegister(0x0000,0x72);
    usleep(1000);

    IAppCard->writeRegister(0x0000,0x94);
    usleep(1000);

    hwInterface->Drive(STARTDRIVE);
    //    IAppCard->startDrive(1);
    //    while((IAppCard->readRegister(0x12)& 0x0001));
    //    usleep(100);
}
void MainWindow::on_butStop_clicked()
{
    IAppCard->stopDrive();
    while((IAppCard->readRegister(0x12)& 0x0002));
    usleep(100);
}


void MainWindow::on_butRefresh_clicked()
{
    if(rescaleAxis){
        xAxisLower=-1;
        xAxisUpper=500;
        yAxisLower=-5;
        yAxisUpper=5;
        ui->customPlot->xAxis->setRange(xAxisLower, xAxisUpper);
        ui->customPlot->yAxis->setRange(yAxisLower, yAxisUpper);
        ui->customPlot->replot();
        rescaleAxis=false;
    }
    else{
        ui->customPlot->rescaleAxes(true);
        ui->customPlot->replot();
        rescaleAxis=true;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::GenerateHexPattern()
{
    //	FILE *fpWaveFile;
    //	fpWaveFile = fopen("./DFIFOAWGDrive.txt","w");
    //	short l_nHexValue = 0;
    //	if(fpWaveFile == 0)
    //		printf("File I/O error\n");
    //	for(short int l_nPreIndex=0;l_nPreIndex<0;l_nPreIndex++)
    //	{
    //		l_nHexValue = (0.6) * ((pow(2,14))-1) / (2 * (0.6));
    //		fprintf(fpWaveFile,"%X\n",l_nHexValue);
    //	}
    //	for(int l_nIndex=0;l_nIndex<500;l_nIndex++)
    //	{
    //		if( m_bUnipolar == true)
    //		{
    //			l_nHexValue = (m_nY[l_nIndex]) *((pow(2,14))-1)/(m_nAmplitude*2.0);
    //			l_nHexValue = l_nHexValue + 8192;
    //		}
    //		else
    //		{
    //			double l_nRefPoint = 0.0;
    //			l_nRefPoint = m_nY[l_nIndex];
    //
    //			l_nHexValue = ((l_nRefPoint)+0.6) * ((pow(2,14))-1) / (2 * (0.6));
    //		}
    //		QString l_strHexValue;
    //
    //		fprintf(fpWaveFile,"%X\n",l_nHexValue & 0x00003FFF);
    //	}
    //	if(m_nCycles==1)
    //		fprintf(fpWaveFile,"%X\n",0x1FFF);
    //	for(short int l_nPostIndex=0;l_nPostIndex<0;l_nPostIndex++)
    //	{
    //		l_nHexValue = (0.6) * ((pow(2,14))-1) / (2 * (0.6));
    //		fprintf(fpWaveFile,"%X\n",l_nHexValue);
    //	}
    //	fclose(fpWaveFile);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    FILE *fpWaveFile;
    fpWaveFile = fopen("./DFIFOAWGDrive.txt","w");
    if(fpWaveFile == 0)
        printf("File I/O error\n");

    short int l_nHexValue = 0;

    l_nHexValue = (1.0) * ((pow(2,14))-1) / (2 * (1.0));
    fprintf(fpWaveFile,"%X\n",l_nHexValue);

    for(int l_nIndex=0;l_nIndex<m_nCount;l_nIndex++){
    	if(l_nIndex>m_nCount){
            l_nHexValue = (1.0) * ((pow(2,14))-1) / (2 * (1.0));
    	}else{
            l_nHexValue=(((m_nY[l_nIndex]*1.0)+1.0) * ((pow(2,14))-1))/(2*1.0);
            fprintf(fpWaveFile,"%X\n",l_nHexValue & 0x00003FFF);
    	}
    }

    //    l_nHexValue = (1.0) * ((pow(2,14))-1) / (2 * (1.0));
    //    fprintf(fpWaveFile,"%X\n",l_nHexValue);

    fclose(fpWaveFile);

}

void MainWindow::loadRAM()
{
    ISPIMemory->accessSPIMemory(APPLICATIONCARD);
    ISPIMemory->setHardwarwObject(IAppCard);

    FILE *l_nFD;
    unsigned short int *m_nWriteData;
    unsigned int l_nFileData=0;
    int l_nIndex=0;

    m_nWriteData = new unsigned short int[m_nCount];
    l_nFD = fopen("./DFIFOAWGDrive.txt","r");
    if(l_nFD == 0)
        printf("File I/O error\n");

    qDebug()<<"SRAM Load Started...";

    while(l_nIndex<m_nCount){
        if(feof(l_nFD))
            l_nFileData =0;
        else
            fscanf(l_nFD,"%x",&l_nFileData);
        m_nWriteData[l_nIndex]=l_nFileData;
        l_nIndex = l_nIndex + 1;
    }
    fclose(l_nFD);

    qDebug()<<"SRAM Data Acquired...index:"<<l_nIndex;

    ISPIMemory->accessSPIRAM(DRIVERAM);
    ISPIMemory->writeAppCardSRAM(0x0000, l_nIndex, &m_nWriteData[0]);   usleep(1000);

    qDebug()<<"SRAM Loaded...";
}

void MainWindow::on_butAppBck_clicked()
{
    QWidget *newWidget = testjig->getPTAppBckPsoc();
    newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
    newWidget->show();
}
