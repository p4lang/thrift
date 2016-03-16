/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <p4thrift/TApplicationException.h>
#include <p4thrift/protocol/TProtocol.h>

namespace p4 { namespace thrift {

uint32_t TApplicationException::read(p4::thrift::protocol::TProtocol* iprot) {
  uint32_t xfer = 0;
  std::string fname;
  p4::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == p4::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
    case 1:
      if (ftype == p4::thrift::protocol::T_STRING) {
        xfer += iprot->readString(message_);
      } else {
        xfer += iprot->skip(ftype);
      }
      break;
    case 2:
      if (ftype == p4::thrift::protocol::T_I32) {
        int32_t type;
        xfer += iprot->readI32(type);
        type_ = (TApplicationExceptionType)type;
      } else {
        xfer += iprot->skip(ftype);
      }
      break;
    default:
      xfer += iprot->skip(ftype);
      break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();
  return xfer;
}

uint32_t TApplicationException::write(p4::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("TApplicationException");
  xfer += oprot->writeFieldBegin("message", p4::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(message_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("type", p4::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(type_);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

}} // p4::thrift
