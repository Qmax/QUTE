#ifndef MACROS_H
#define MACROS_H
/*
                        _______________________________________________________
 Function   | scope1 | scope2    | VI 1      | VI 2    | DMM | FG  | SL  | ICM |
 Bit                |____7___|____6___|__5___|__4___|__3__|__2__|__1__|__0__|

 */

#define SCOPE1             0X80
#define SCOPE2             0X40
#define VI1                        0X20
#define VI2                        0X10
/*#define SCOPE	             0X80
#define VI						0x20*/
#define DMM                   0X08
#define FG                         0X04
#define SL                          0X02
#define ICM                      0X01

#define VI1_SC2              0x60
#define VI2_SC2              0x50
#define SL_SC2                0x42
#define DMM_SC2        0x48
#define FG_SC1_SC2    0xc4

#define reset_relay 									0x40
#define l_nonTopRelay 							0x41
#define l_nonBottomRelay						0x42
#define l_noffTopRelay 							0x43
#define l_noffBottomRelay						0x44
#define l_nReadRlyStatus 								0x45
#define embeddedKey 							0x01
#define  l_nExternalMuxValue					0x09			/*External Mux*/

#define		GPIOINT		0x0100
#define 	NOINT		0x0000

#endif // MACROS_H
