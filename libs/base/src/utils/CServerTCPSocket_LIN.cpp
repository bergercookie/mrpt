/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+
   */

#include "base-precomp.h" // Precompiled headers

#include <mrpt/config.h>

#if defined(MRPT_OS_LINUX) || defined(MRPT_OS_APPLE)

#include <mrpt/system.h>
#include <mrpt/utils/CClientTCPSocket.h>
#include <mrpt/utils/CServerTCPSocket.h>

// Platform specific headers:
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <unistd.h>
//#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

using namespace mrpt;
using namespace mrpt::utils;

/*---------------------------------------------------------------
                                        Constructor
 ---------------------------------------------------------------*/
CServerTCPSocket::CServerTCPSocket(unsigned short listenPort,
                                   const std::string &IPaddress,
                                   int maxConnectionsWaiting,
                                   mrpt::utils::VerbosityLevel verbosityLevel)
    : COutputLogger("CServerTCPSocket") {
  MRPT_TRY_START;
  setVerbosityLevel(verbosityLevel);
  setupSocket(listenPort, IPaddress, maxConnectionsWaiting);
  MRPT_TRY_END;
}

/*---------------------------------------------------------------
                                        Destructor
 ---------------------------------------------------------------*/
CServerTCPSocket::~CServerTCPSocket() {
  // Delete socket:
  if (m_serverSock != -1)
    close(m_serverSock);
}

#endif // Linux
