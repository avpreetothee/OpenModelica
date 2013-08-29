/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-2010, Linköpings University,
 * Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF THIS OSMC PUBLIC
 * LICENSE (OSMC-PL). ANY USE, REPRODUCTION OR DISTRIBUTION OF
 * THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE OF THE OSMC
 * PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linköpings University, either from the above address,
 * from the URL: http://www.ida.liu.se/projects/OpenModelica
 * and in the OpenModelica distribution.
 *
 * This program is distributed  WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#include <stdio.h>
#include <meta_modelica.h>

#if defined(__MINGW32__) || defined(_MSC_VER)

extern int Socket_waitforconnect(int _inInteger)
{
  fprintf(stderr, "Socket NYI\n");
  MMC_THROW();
}

extern const char* Socket_handlerequest(int _inInteger)
{
  fprintf(stderr, "Socket NYI\n");
  MMC_THROW();
}

extern void Socket_cleanup()
{
  fprintf(stderr, "Socket NYI\n");
  MMC_THROW();
}

extern void Socket_close(int _inInteger)
{
  fprintf(stderr, "Socket NYI\n");
  MMC_THROW();
}

extern void Socket_sendreply(int _inInteger, const char* _inString)
{
  fprintf(stderr, "Socket NYI\n");
  MMC_THROW();
}

#else

#include "socketimpl.c"
#include "meta_modelica.h"
#include "ModelicaUtilities.h"

extern const char* Socket_handlerequest(int sock)
{
  char *str = Socket_handlerequest(sock);
  char *res = strcpy(ModelicaAllocateString(strlen(str)),str);
  free(str);
  return res;
}
#endif
