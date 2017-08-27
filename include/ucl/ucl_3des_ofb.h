/*============================================================================
 *
 *	ucl_3des_ofb.h
 *
 *==========================================================================*/
/*============================================================================
 *
 * Copyright (c) 2002-2006 Innova Card.
 * All Rights Reserved. Do not disclose.
 *
 * This software is the confidential and proprietary information of
 * Innova Card ("Confidential Information"). You shall not
 * disclose such Confidential Information and shall use it only in
 * accordance with the terms of the license agreement you entered
 * into with Innova Card.
 *
 * Innova Card makes no representations or warranties about the suitability of
 * the software, either express or implied, including but not limited to
 * the implied warranties of merchantability, fitness for a particular purpose,
 * or non-infrigement. Innova Card shall not be liable for any damages suffered
 * by licensee as the result of using, modifying or distributing this software
 * or its derivatives.
 *
 *==========================================================================*/
/*============================================================================
 *
 * Purpose :
 *
 *==========================================================================*/
#ifndef _UCL_3DES_OFB_H_
#define _UCL_3DES_OFB_H_

#include "ucl_3des.h"

/** @file ucl_3des_ofb.h
 * @defgroup UCL_OFB_3DES 3DES OFB
 * Encrypt/Decrypt with 3DES in 64-bit OFB (Output Feedback) mode.
 * 
 * @par Header:
 * @link ucl_3des_ofb.h ucl_3des_ofb.h @endlink
 *
 * @ingroup UCL_OFB
 */


/*============================================================================*/
/** <b>3DES-OFB</b>.
 * Complete process.
 *
 * @pre	@li The byte length must be a multiple of 8.
 *		@li Input and Output Data have the same length.
 * 		@li The key length is 16 or 24 bytes (See @link UCL_3DES 3DES @endlink).
 *
 * @param[out]	dataOut 		Pointer to the output data
 * @param[in]	dataIn			Pointer to the input data
 * @param[in]	key				Pointer to the 3DES Key
 * @param[in]	IV				Pointer to the initialization vector
 * @param[in]	data_byteLen	Data byte length
 * @param[in]	mode			The mode (Encryption/Decryption):
 *									@li #UCL_CIPHER_ENCRYPT
 *									@li #UCL_CIPHER_DECRYPT
 *
 * @return	Error code
 *
 * @retval	#UCL_OK				if no error occurred
 * @retval	#UCL_INVALID_INPUT	if one of the input is the pointer NULL
 * @retval	#UCL_INVALID_OUTPUT 	if one of the output is the pointer NULL
 * @retval	#UCL_INVALID_ARG		if @p data_byteLen is not a multiple of 8
 *
 * @note	This mode requires an initialization vector @p IV to combine with
 * 			the first plaintext block. The IV need not be secret, but it must
 * 			be unpredictable. @n
 * 			We recommand to generate it with the USIP&reg; TRNG.
 *
 * @see UCL_3DES
 *
 * @ingroup UCL_OFB_3DES
 */
int ucl_3des_ofb(u8 *dataOut, u8 *dataIn, u8 *key, u8 *IV,
	u32 data_byteLen, int mode);


/*============================================================================*/
/** <b>3DES-OFB Init</b>.
 * Initialize 3DES OFB Context.
 *
 * @pre	The key length is 16 or 24 bytes (See @link UCL_3DES 3DES @endlink).
 *
 * @param[out]	ctx		Pointer to the context
 * @param[in]	key		Pointer to the 3DES Key
 * @param[in]	IV		Pointer to the initialization vector
 * @param[in]	mode	The mode (Encryption/Decryption) :
 *							@li #UCL_CIPHER_ENCRYPT
 *							@li #UCL_CIPHER_DECRYPT
 *
 * @return	Error code
 *
 * @retval	#UCL_OK				if no error occurred
 * @retval	#UCL_INVALID_INPUT	if the input is the pointer #NULL
 * @retval	#UCL_INVALID_OUTPUT 	if the output is the pointer #NULL
 * @retval	#UCL_INVALID_MODE	if the mode is not one of those 3described
 *
 * @ingroup UCL_OFB_3DES
 */
int ucl_3des_ofb_init(ucl_3des_ctx_t *ctx, u8 *key, u8 *IV,
	int mode);


/*============================================================================*/
/** <b>3DES-OFB Core</b>.
 * Process the Data.
 *
 * @pre	@li The byte length must be a multiple of 8.
 *		@li Input and Output Data have the same length.
 *
 * @param[out]		dataOut			Pointer to the procesed data
 * @param[in,out]	ctx				Pointer to the context
 * @param[in]		dataIn			Pointer to the data
 * @param[in]		data_byteLen	Data byte length
 *
 * @return	Error code
 * @retval	#UCL_OK				if no error occurred
 * @retval	#UCL_INVALID_INPUT	if one of the input is the pointer #NULL
 * @retval	#UCL_INVALID_OUTPUT 	if the output is the pointer #NULL
 * @retval	#UCL_INVALID_ARG		if the byte length is not a multiple of 8
 *
 * @ingroup UCL_OFB_3DES
 */
int ucl_3des_ofb_core(u8 *dataOut, ucl_3des_ctx_t *ctx,
	u8 *dataIn, u32 data_byteLen);


/*============================================================================*/
/** <b>3DES-OFB Finish</b>.
 * Zeroize the context.
 *
 * @param[out,in]	ctx	Pointer to the context
 *
 * @return	Error code
 *
 * @retval	#UCL_OK				if no error occurred
 * @retval	#UCL_INVALID_OUTPUT 	if the output is the pointer #NULL
 *
 * @ingroup UCL_OFB_3DES
 */
int ucl_3des_ofb_finish(ucl_3des_ctx_t *ctx);


#endif /* _UCL_3DES_OFB_H_ */
