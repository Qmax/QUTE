#include "ptgpiopininterface.h"

int toggleGPIO(char* gpioNo,int val){

	int fd;

	if ((fd = open(gpioNo, O_RDWR)) < 0){
		printf("open error: %s\n\n", strerror(errno));
		return 0;
	}

	if ((ioctl(fd, GPIO_CONFIG_AS_OUT)) < 0){
		printf("o/p config error: %s\n\n", strerror(errno));
		return 0;
	}

	if( (write( fd, (char *)&val, sizeof( char ) ) ) != sizeof( char ) ){
		printf("[ERROR] write (led): %s\n\n", strerror(errno));
		return 0;
	}

	close(fd);

	return 1;
}
PTGPIOPinInterface::PTGPIOPinInterface() {
    //qDebug()<<"----------------------------GPIO PIN INTERFACE OPENED----------------------------";

    touch_value=1;
	toggleGPIO("/dev/gpio/65",1);
	toggleGPIO("/dev/gpio/66",1);
}
PTGPIOPinInterface::~PTGPIOPinInterface() {
    //qDebug()<<"----------------------------GPIO PIN INTERFACE CLOSED----------------------------";

}
int PTGPIOPinInterface:: toggleTouchButton(){
	if(touch_value==1){
		touch_value=0;
		//qDebug() << ("\nTouch Disabled");
	}else{
		touch_value=1;
		//qDebug() << ("\nTouch Enabled");
	}
	toggleGPIO("/dev/gpio/124",touch_value);
}

int PTGPIOPinInterface:: illuminateScaleButton(int val){
	toggleGPIO("/dev/gpio/65",val);
	return val;
}
int PTGPIOPinInterface:: illuminateRunStopButton(int val){
	toggleGPIO("/dev/gpio/66",val);
	return val;
}
int PTGPIOPinInterface::killSystem(){
	toggleGPIO("/dev/gpio/85",1);
}

Q_EXPORT_PLUGIN2(InterfaceGPIOPins, PTGPIOPinInterface);
