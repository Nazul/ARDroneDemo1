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
 ============================================================================
 Name        : ARDroneDemo1.c
 Author      : Mario Contreras
 Version     :
 Copyright   : Copyright 2016 Mario Contreras - marioc@nazul.net
 Description : A basic demo app using Parrot AR.Drone 2.0
 ============================================================================
 */

// Standard
#include <stdio.h>
#include <stdlib.h>

// AR.Drone SDK 2.0.1
//ARDroneLib
#include <utils/ardrone_time.h>
#include <ardrone_tool/Navdata/ardrone_navdata_client.h>
#include <ardrone_tool/Control/ardrone_control.h>
#include <ardrone_tool/UI/ardrone_input.h>
//Common
#include <config.h>
#include <ardrone_api.h>
//VP_SDK
#include <VP_Os/vp_os_types.h>
#include <ATcodec/ATcodec_api.h>
#include <VP_Os/vp_os_print.h>
#include <VP_Api/vp_api_thread_helper.h>
#include <VP_Os/vp_os_signal.h>

//Local project
//#include "Navdata/navdata.h"
#include "Common/config.h"
#include "UI/ardrone_ini.h"


static config_t cfg;
static int32_t exit_ihm_program = 1;

/* Implementing Custom methods for the main function of an ARDrone application */
int main(int argc, char** argv) {
	printf("Simple AR.Drone Demo 1 - build %s %s\n\n", __DATE__, __TIME__);
	return ardrone_tool_main(argc, argv);
}

/* The delegate object calls this method during initialization of an ARDrone application */
C_RESULT ardrone_tool_init_custom(void) {
	/* Registering for a new device of game controller */
	//ardrone_tool_input_add( &gamepad );

	/* Start all threads of your application */
	//START_THREAD(video_stage, NULL);

    load_ini();
    printf("Default control : %s (0x%08x, %s)\n", default_control->name, default_control->serial, default_control->filename);
    ardrone_tool_input_add(&control_device);
    printf("Device added\n");
    cfg.default_control = default_control;
    cfg.devices = devices;
    printf("Config changed\n");

    return C_OK;
}

/* The delegate object calls this method when the event loop exit */
C_RESULT ardrone_tool_shutdown_custom(void) {
	/* Relinquish all threads of your application */
	//JOIN_THREAD(video_stage);

	/* Unregistering for the current device */
	// ardrone_tool_input_remove( &gamepad );
	ardrone_tool_input_remove(&control_device);

	return C_OK;
}

/* The event loop calls this method for the exit condition */
bool_t ardrone_tool_exit() {
	return exit_ihm_program == 0;
}

C_RESULT signal_exit() {
	exit_ihm_program = 0;

	return C_OK;
}

/* Implementing thread table in which you add routines of your application and those provided by the SDK */
BEGIN_THREAD_TABLE
	THREAD_TABLE_ENTRY( ardrone_control, 20 )
	THREAD_TABLE_ENTRY( navdata_update, 20 )
	//THREAD_TABLE_ENTRY( video_stage, 20 )
END_THREAD_TABLE

// EOF
