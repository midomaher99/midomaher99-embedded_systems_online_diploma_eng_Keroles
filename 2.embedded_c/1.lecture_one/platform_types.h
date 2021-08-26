#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H
/*--------------------signed integers--------------------*/
	typedef	char 							sint8;
	typedef	short 							sint16;
	typedef	int 							sint32;
	typedef	long long 						sint64;
/*--------------------unsigned integers--------------------*/	
	typedef unsigned char					uint8;
	typedef unsigned short					uint16;
	typedef unsigned int 		 			uint32;
	typedef unsigned long long				uint64;
/*--------------------doubles--------------------*/
	typedef	float							float32;
	typedef	double							float64;
	typedef long double						float80;
/*-------------------volatile signed integers--------------------*/
	typedef	volatile char 					vint8;
	typedef	volatile short 					vint16;
	typedef	volatile int 					vint32;
	typedef	volatile long long 				vint64;
/*--------------------volatile unsigned integers--------------------*/	
	typedef volatile unsigned char			vuint8;
	typedef volatile unsigned short			vuint16;
	typedef volatile unsigned int  			vuint32;
	typedef volatile unsigned long long		vuint64;
/*--------------------volatile doubles--------------------*/
	typedef	volatile float					vfloat32;
	typedef	volatile double					vfloat64;
	typedef volatile long double			vfloat80;
/*--------------------boolean--------------------*/
	typedef unsigned int 					boolean;
	typedef volatile unsigned int 			vboolean;	
	#endif