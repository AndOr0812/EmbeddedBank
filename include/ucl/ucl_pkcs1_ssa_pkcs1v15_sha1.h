/*============================================================================
 *
 *	ucl_pkcs1_ssa_pkcs1v15_sha1.h
 *
 *==========================================================================*/
/*============================================================================
 *
 * Copyright (c) 2002-2006 Innova Card. All rights reserved. Do not disclose.
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
 * Purpose : PKCS#1 V2.1 RSASSA-PKCS1V15 with SHA1
 *
 *==========================================================================*/
#ifndef _UCL_RSA_SSA_PKCS1V15_SHA1_H_
#define _UCL_RSA_SSA_PKCS1V15_SHA1_H_

#include "ucl_rsa.h"

/** @file ucl_pkcs1_ssa_pkcs1v15_sha1.h
 * @defgroup UCL_PKCS1V21_SSA_PKCSV15_SHA1 RSASSA-PKCS1V15 SHA1
 * Signature scheme RSA PKCS#1 V1.5 using the hash function SHA1.
 * 
 * @par Header:
 * @link ucl_pkcs1_ssa_pkcs1v15_sha1.h ucl_pkcs1_ssa_pkcs1v15_sha1.h @endlink
 *
 * @ingroup UCL_PKCS1V21_SSA_PKCS1V15
 */


/*============================================================================*/
/** <b>RSASSA-PKCS1V15-SHA1 Signature Generation</b>.
 * Signature generation using hash function SHA1.
 *
 * @param[out]	signature		Pointer to the encoded message
 * @param[in]	message			The message used to the signature
 * @param[in]	message_length	The message length byte (at most $2^32 -1$)
 * @param[in]	keyPr			RSA private key
 *
 * @return	Error code
 *
 * @retval	#UCL_OK	if no error occurred
 *
 * @see UCL_RSA
 *
 * @ingroup UCL_PKCS1V21_SSA_PKCSV15_SHA1
 */
int ucl_pkcs1_ssa_pkcs1v15_sha1_sign(u8 *signature, u8 *message,
	u32 message_length, ucl_rsa_private_key_t *keyPr);


/*============================================================================*/
/** <b>RSASSA-PKCS1V15-SHA1 CRT Signature Generation</b>.
 * CRT Signature generation using hash function SHA1.
 *
 * @param[out]	signature		Pointer to the encoded message
 * @param[in]	message			The message used to the signature
 * @param[in]	message_length	The message length byte (at most $2^32 -1$)
 * @param[in]	keyPr			RSA CRT private key
 *
 * @return	Error code
 *
 * @retval	#UCL_OK	if no error occurred
 *
 * @see UCL_RSA
 *
 * @ingroup UCL_PKCS1V21_SSA_PKCSV15_SHA1
 */
int ucl_pkcs1_ssa_pkcs1v15_sha1_crt_sign(u8 *signature, u8 *message,
	u32 message_length, ucl_rsa_crt_private_key_t *keyPr);


/*============================================================================*/
/** <b>RSASSA-PKCS1V15-SHA1 Signature Verification</b>.
 * Signature verification using hash function SHA1.
 *
 * @param[out]	signature		Pointer to the encoded message
 * @param[in]	message			The message used to the signature
 * @param[in]	message_length	The message length byte (at most $2^32 -1$)
 * @param[in]	keyPu			RSA CRT private key
 *
 * @return	Error code
 *
 * @retval	#UCL_OK	if the signature is valid
 *
 * @see UCL_RSA
 *
 * @ingroup UCL_PKCS1V21_SSA_PKCSV15_SHA1
 */
int ucl_pkcs1_ssa_pkcs1v15_sha1_verify(u8 *signature, u8 *message,
	u32 message_length, ucl_rsa_public_key_t *keyPu);


#endif //_UCL_RSA_SSA_PKCS1V15_SHA1_H_
