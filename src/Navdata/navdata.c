/*
 * Copyright 2016 Mario Contreras - marioc@nazul.net.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * navdata.c
 *
 *  Created on: Mar 5, 2016
 *      Author: Mario Contreras - marioc@nazul.net
 */

// Standard
#include <stdio.h>

// AR.Drone SDK 2.0.1
//#include <ardrone_tool/Navdata/ardrone_navdata_client.h>

//Local project
#include "navdata.h"


/* Initialization local variables before event loop  */
C_RESULT demo_navdata_client_init( void* data ) {
	return C_OK;
}

/* Receving navdata during the event loop */
C_RESULT demo_navdata_client_process( const navdata_unpacked_t* const navdata ) {
	const navdata_demo_t*nd = &navdata->navdata_demo;

	printf("=====================\nNavdata for flight demonstrations =====================\n\n");

	printf("Control state : %i\n",nd->ctrl_state);
	printf("Battery level : %i mV\n",nd->vbat_flying_percentage);
	printf("Orientation   : [Theta] %4.3f  [Phi] %4.3f  [Psi] %4.3f\n",nd->theta,nd->phi,nd->psi);
	printf("Altitude      : %i\n",nd->altitude);
	printf("Speed         : [vX] %4.3f  [vY] %4.3f  [vZPsi] %4.3f\n",nd->theta,nd->phi,nd->psi);

	printf("\033[8A");

	return C_OK;
}

/* Relinquish the local resources after the event loop exit */
C_RESULT demo_navdata_client_release( void ) {
	return C_OK;
}

/* Registering to navdata client */
BEGIN_NAVDATA_HANDLER_TABLE
	NAVDATA_HANDLER_TABLE_ENTRY(demo_navdata_client_init, demo_navdata_client_process, demo_navdata_client_release, NULL)
END_NAVDATA_HANDLER_TABLE


// EOF
