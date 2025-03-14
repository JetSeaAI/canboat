/*

Defines to interface with an Actisense NGT-1

(C) 2009-2025, Kees Verruijt, Harlingen, The Netherlands.

This file is part of CANboat.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

 */

/* ASCII characters used to mark packet start/stop */

#define STX (0x02) /* Start packet */
#define ETX (0x03) /* End packet */
#define DLE (0x10) /* Start pto encode a STX or ETX send DLE+STX or DLE+ETX */
#define ESC (0x1B) /* Escape */

/* Actisense message structure is:

   DLE STX <command> <len> [<data> ...]  <checksum> DLE ETX

   <command> is a byte from the list below.
   In <data> any DLE characters are double escaped (DLE DLE).
   <len> encodes the unescaped length.
   <checksum> is such that the sum of all unescaped data bytes plus the command
              byte plus the length adds up to zero, modulo 256.
*/

#define N2K_MSG_RECEIVED (0x93) /* Receive standard N2K message */
#define N2K_MSG_SEND (0x94)     /* Send N2K message */
#define NGT_MSG_RECEIVED (0xA0) /* Receive NGT specific message */
#define NGT_MSG_SEND (0xA1)     /* Send NGT message */
