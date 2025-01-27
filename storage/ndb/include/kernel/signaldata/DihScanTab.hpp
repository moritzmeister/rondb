/* Copyright (c) 2008, 2016, Oracle and/or its affiliates. All rights reserved.
   Copyright (c) 2021, 2021, Logical Clocks and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#ifndef DIH_SCAN_TAB_HPP
#define DIH_SCAN_TAB_HPP

#include "SignalData.hpp"

#define JAM_FILE_ID 108


/**
 * DihScanTabReq
 */
struct DihScanTabReq
{
  STATIC_CONST( SignalLength = 6 );
  STATIC_CONST( RetryInterval = 5 );

  Uint32 tableId;
  Uint32 senderData;
  Uint32 senderRef;
  Uint32 schemaTransId;
  union {
    void * jamBufferPtr;
    Uint32 jamBufferStorage[2];
  };
};

/**
 * DihScanTabConf
 */
struct DihScanTabConf
{
  STATIC_CONST( SignalLength = 7 );
  STATIC_CONST( InvalidCookie = RNIL );

  Uint32 tableId;
  Uint32 senderData;
  Uint32 fragmentCount;
  Uint32 noOfBackups;
  Uint32 scanCookie;
  Uint32 scanSchemaVersionCookie;
  Uint32 reorgFlag;
};

/**
 * DihScanTabRef
 */
struct DihScanTabRef
{
  enum ErrorCode {
    ErroneousState = 0,
    ErroneousTableState = 1
  };
  STATIC_CONST( SignalLength = 5 );

  Uint32 tableId;
  Uint32 senderData;
  Uint32 error;
  Uint32 tableStatus; // Dbdih::TabRecord::tabStatus
  Uint32 schemaTransId;
};

struct DihScanTabCompleteRep
{
  STATIC_CONST( SignalLength = 5 );

  Uint32 tableId;
  Uint32 schemaVersionCookie;
  Uint32 scanCookie;
  union {
    void * jamBufferPtr;
    Uint32 jamBufferStorage[2];
  };
};


#undef JAM_FILE_ID

#endif
