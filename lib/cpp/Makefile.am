#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements. See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership. The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the
# specific language governing permissions and limitations
# under the License.
#

AUTOMAKE_OPTIONS = subdir-objects

moc_%.cpp: %.h
	$(QT_MOC) $(QT_CFLAGS) $< -o $@

SUBDIRS = .

if WITH_TESTS
SUBDIRS += test
endif

pkgconfigdir = $(libdir)/pkgconfig

lib_LTLIBRARIES = libp4thrift.la
pkgconfig_DATA = thrift.pc
libp4thrift_la_LDFLAGS = -release $(VERSION) $(BOOST_LDFLAGS)

## We only build the extra libraries if we have the dependencies,
## but we install all of the headers unconditionally.
if AMX_HAVE_LIBEVENT
lib_LTLIBRARIES += libp4thriftnb.la
pkgconfig_DATA += thrift-nb.pc
endif
if AMX_HAVE_ZLIB
lib_LTLIBRARIES += libp4thriftz.la
pkgconfig_DATA += thrift-z.pc
endif
if AMX_HAVE_QT
lib_LTLIBRARIES += libp4thriftqt.la
pkgconfig_DATA += thrift-qt.pc
endif

AM_CXXFLAGS = -Wall -Wextra -pedantic
AM_CPPFLAGS = $(BOOST_CPPFLAGS) -I$(srcdir)/src
AM_LDFLAGS = $(BOOST_LDFLAGS)

# Define the source files for the module

libp4thrift_la_SOURCES = src/p4thrift/Thrift.cpp \
                       src/p4thrift/TApplicationException.cpp \
                       src/p4thrift/VirtualProfiling.cpp \
                       src/p4thrift/concurrency/ThreadManager.cpp \
                       src/p4thrift/concurrency/TimerManager.cpp \
                       src/p4thrift/concurrency/Util.cpp \
                       src/p4thrift/protocol/TDebugProtocol.cpp \
                       src/p4thrift/protocol/TDenseProtocol.cpp \
                       src/p4thrift/protocol/TJSONProtocol.cpp \
                       src/p4thrift/protocol/TBase64Utils.cpp \
                       src/p4thrift/protocol/TMultiplexedProtocol.cpp \
                       src/p4thrift/transport/TTransportException.cpp \
                       src/p4thrift/transport/TFDTransport.cpp \
                       src/p4thrift/transport/TFileTransport.cpp \
                       src/p4thrift/transport/TSimpleFileTransport.cpp \
                       src/p4thrift/transport/THttpTransport.cpp \
                       src/p4thrift/transport/THttpClient.cpp \
                       src/p4thrift/transport/THttpServer.cpp \
                       src/p4thrift/transport/TSocket.cpp \
                       src/p4thrift/transport/TPipe.cpp \
                       src/p4thrift/transport/TPipeServer.cpp \
                       src/p4thrift/transport/TSSLSocket.cpp \
                       src/p4thrift/transport/TSocketPool.cpp \
                       src/p4thrift/transport/TServerSocket.cpp \
                       src/p4thrift/transport/TSSLServerSocket.cpp \
                       src/p4thrift/transport/TTransportUtils.cpp \
                       src/p4thrift/transport/TBufferTransports.cpp \
                       src/p4thrift/server/TServer.cpp \
                       src/p4thrift/server/TSimpleServer.cpp \
                       src/p4thrift/server/TThreadPoolServer.cpp \
                       src/p4thrift/server/TThreadedServer.cpp \
                       src/p4thrift/async/TAsyncChannel.cpp \
                       src/p4thrift/processor/PeekProcessor.cpp

if WITH_BOOSTTHREADS
libp4thrift_la_SOURCES += src/p4thrift/concurrency/BoostThreadFactory.cpp \
                        src/p4thrift/concurrency/BoostMonitor.cpp \
                        src/p4thrift/concurrency/BoostMutex.cpp
else
libp4thrift_la_SOURCES += src/p4thrift/concurrency/Mutex.cpp \
                        src/p4thrift/concurrency/Monitor.cpp \
                        src/p4thrift/concurrency/PosixThreadFactory.cpp
endif

libp4thriftnb_la_SOURCES = src/p4thrift/server/TNonblockingServer.cpp \
                         src/p4thrift/async/TAsyncProtocolProcessor.cpp \
                         src/p4thrift/async/TEvhttpServer.cpp \
                         src/p4thrift/async/TEvhttpClientChannel.cpp

libp4thriftz_la_SOURCES = src/p4thrift/transport/TZlibTransport.cpp

libp4thriftqt_la_MOC = src/p4thrift/qt/moc_TQTcpServer.cpp
libp4thriftqt_la_SOURCES = $(libp4thriftqt_la_MOC) \
                         src/p4thrift/qt/TQIODeviceTransport.cpp \
                         src/p4thrift/qt/TQTcpServer.cpp
CLEANFILES = $(libp4thriftqt_la_MOC)

# Flags for the various libraries
libp4thriftnb_la_CPPFLAGS = $(AM_CPPFLAGS) $(LIBEVENT_CPPFLAGS)
libp4thriftz_la_CPPFLAGS  = $(AM_CPPFLAGS) $(ZLIB_CPPFLAGS)
libp4thriftqt_la_CPPFLAGS = $(AM_CPPFLAGS) $(QT_CFLAGS)
libp4thriftnb_la_CXXFLAGS = $(AM_CXXFLAGS)
libp4thriftz_la_CXXFLAGS  = $(AM_CXXFLAGS)
libp4thriftqt_la_CXXFLAGS  = $(AM_CXXFLAGS)
libp4thriftnb_la_LDFLAGS  = -release $(VERSION) $(BOOST_LDFLAGS)
libp4thriftz_la_LDFLAGS   = -release $(VERSION) $(BOOST_LDFLAGS)
libp4thriftqt_la_LDFLAGS   = -release $(VERSION) $(BOOST_LDFLAGS) $(QT_LIBS)

include_p4thriftdir = $(includedir)/p4thrift
include_p4thrift_HEADERS = \
                         $(top_builddir)/config.h \
                         src/p4thrift/thrift-config.h \
                         src/p4thrift/TDispatchProcessor.h \
                         src/p4thrift/P4Thrift.h \
                         src/p4thrift/TReflectionLocal.h \
                         src/p4thrift/TProcessor.h \
                         src/p4thrift/TApplicationException.h \
                         src/p4thrift/TLogging.h \
                         src/p4thrift/cxxfunctional.h \
                         src/p4thrift/TToString.h

include_concurrencydir = $(include_p4thriftdir)/concurrency
include_concurrency_HEADERS = \
                         src/p4thrift/concurrency/BoostThreadFactory.h \
                         src/p4thrift/concurrency/Exception.h \
                         src/p4thrift/concurrency/Mutex.h \
                         src/p4thrift/concurrency/Monitor.h \
                         src/p4thrift/concurrency/PlatformThreadFactory.h \
                         src/p4thrift/concurrency/PosixThreadFactory.h \
                         src/p4thrift/concurrency/StdMonitor.cpp \
                         src/p4thrift/concurrency/StdMutex.cpp \
                         src/p4thrift/concurrency/StdThreadFactory.cpp \
                         src/p4thrift/concurrency/StdThreadFactory.h \
                         src/p4thrift/concurrency/Thread.h \
                         src/p4thrift/concurrency/ThreadManager.h \
                         src/p4thrift/concurrency/TimerManager.h \
                         src/p4thrift/concurrency/FunctionRunner.h \
                         src/p4thrift/concurrency/Util.h

include_protocoldir = $(include_p4thriftdir)/protocol
include_protocol_HEADERS = \
                         src/p4thrift/protocol/TBinaryProtocol.h \
                         src/p4thrift/protocol/TBinaryProtocol.tcc \
                         src/p4thrift/protocol/TCompactProtocol.h \
                         src/p4thrift/protocol/TCompactProtocol.tcc \
                         src/p4thrift/protocol/TDenseProtocol.h \
                         src/p4thrift/protocol/TDebugProtocol.h \
                         src/p4thrift/protocol/TBase64Utils.h \
                         src/p4thrift/protocol/TJSONProtocol.h \
                         src/p4thrift/protocol/TMultiplexedProtocol.h \
                         src/p4thrift/protocol/TProtocolDecorator.h \
                         src/p4thrift/protocol/TProtocolTap.h \
                         src/p4thrift/protocol/TProtocolException.h \
                         src/p4thrift/protocol/TVirtualProtocol.h \
                         src/p4thrift/protocol/TProtocol.h

include_transportdir = $(include_p4thriftdir)/transport
include_transport_HEADERS = \
                         src/p4thrift/transport/PlatformSocket.h \
                         src/p4thrift/transport/TFDTransport.h \
                         src/p4thrift/transport/TFileTransport.h \
                         src/p4thrift/transport/TSimpleFileTransport.h \
                         src/p4thrift/transport/TServerSocket.h \
                         src/p4thrift/transport/TSSLServerSocket.h \
                         src/p4thrift/transport/TServerTransport.h \
                         src/p4thrift/transport/THttpTransport.h \
                         src/p4thrift/transport/THttpClient.h \
                         src/p4thrift/transport/THttpServer.h \
                         src/p4thrift/transport/TSocket.h \
                         src/p4thrift/transport/TPipe.h \
                         src/p4thrift/transport/TPipeServer.h \
                         src/p4thrift/transport/TSSLSocket.h \
                         src/p4thrift/transport/TSocketPool.h \
                         src/p4thrift/transport/TVirtualTransport.h \
                         src/p4thrift/transport/TTransport.h \
                         src/p4thrift/transport/TTransportException.h \
                         src/p4thrift/transport/TTransportUtils.h \
                         src/p4thrift/transport/TBufferTransports.h \
                         src/p4thrift/transport/TShortReadTransport.h \
                         src/p4thrift/transport/TZlibTransport.h

include_serverdir = $(include_p4thriftdir)/server
include_server_HEADERS = \
                         src/p4thrift/server/TServer.h \
                         src/p4thrift/server/TSimpleServer.h \
                         src/p4thrift/server/TThreadPoolServer.h \
                         src/p4thrift/server/TThreadedServer.h \
                         src/p4thrift/server/TNonblockingServer.h

include_processordir = $(include_p4thriftdir)/processor
include_processor_HEADERS = \
                         src/p4thrift/processor/PeekProcessor.h \
                         src/p4thrift/processor/StatsProcessor.h \
                         src/p4thrift/processor/TMultiplexedProcessor.h

include_asyncdir = $(include_p4thriftdir)/async
include_async_HEADERS = \
                     src/p4thrift/async/TAsyncChannel.h \
                     src/p4thrift/async/TAsyncDispatchProcessor.h \
                     src/p4thrift/async/TAsyncProcessor.h \
                     src/p4thrift/async/TAsyncBufferProcessor.h \
                     src/p4thrift/async/TAsyncProtocolProcessor.h \
                     src/p4thrift/async/TEvhttpClientChannel.h \
                     src/p4thrift/async/TEvhttpServer.h

include_qtdir = $(include_p4thriftdir)/qt
include_qt_HEADERS = \
                  src/p4thrift/qt/TQIODeviceTransport.h \
                  src/p4thrift/qt/TQTcpServer.h

THRIFT = $(top_builddir)/compiler/cpp/p4thrift

WINDOWS_DIST = \
             src/p4thrift/windows \
             thrift.sln \
             libthrift.vcxproj \
             libthrift.vcxproj.filters \
             libthriftnb.vcxproj \
             libthriftnb.vcxproj.filters \
             3rdparty.props

EXTRA_DIST = \
             README.md \
             thrift-nb.pc.in \
             thrift.pc.in \
             thrift-z.pc.in \
             thrift-qt.pc.in \
             $(WINDOWS_DIST)
