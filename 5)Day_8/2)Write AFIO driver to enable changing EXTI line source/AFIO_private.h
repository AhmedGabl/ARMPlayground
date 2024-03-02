/*
 * AFIO_private.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Ahmed Abogabl
 */

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

#define AFIO_BASE_ADDRESS 	0x40010000


#define AFIO_EVCR	  *((volatile u32 *)(AFIO_BASE_ADDRESS + 0x00))
#define AFIO_MAPR	  *((volatile u32 *)(AFIO_BASE_ADDRESS + 0x04))
#define AFIO_EXTICR    ((volatile u32 *)(AFIO_BASE_ADDRESS + 0x08))
#define AFIO_MAPR2	  *((volatile u32 *)(AFIO_BASE_ADDRESS + 0x1c))


#endif /* AFIO_PRIVATE_H_ */
