//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013-2019 Automatak, LLC
// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
// LLC (www.automatak.com) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Automatak LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef OPENDNP3_GROUP12_H
#define OPENDNP3_GROUP12_H

#include "opendnp3/app/GroupVariationID.h"
#include <openpal/container/RSlice.h>
#include <openpal/container/WSlice.h>
#include "opendnp3/app/DNPTime.h"
#include "opendnp3/app/DNP3Serializer.h"
#include "opendnp3/app/ControlRelayOutputBlock.h"

namespace opendnp3 {

// Binary Command - Any Variation
struct Group12Var0
{
  static GroupVariationID ID() { return GroupVariationID(12,0); }
};

// Binary Command - CROB
struct Group12Var1
{
  static GroupVariationID ID() { return GroupVariationID(12,1); }

  Group12Var1();

  static uint32_t Size() { return 11; }
  static bool Read(openpal::RSlice&, Group12Var1&);
  static bool Write(const Group12Var1&, openpal::WSlice&);

  uint8_t code;
  uint8_t count;
  uint32_t onTime;
  uint32_t offTime;
  uint8_t status;

  typedef ControlRelayOutputBlock Target;
  static bool ReadTarget(openpal::RSlice&, ControlRelayOutputBlock&);
  static bool WriteTarget(const ControlRelayOutputBlock&, openpal::WSlice&);
  static DNP3Serializer<ControlRelayOutputBlock> Inst() { return DNP3Serializer<ControlRelayOutputBlock>(ID(), Size(), &ReadTarget, &WriteTarget); }
};


}

#endif
