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
 * config.h
 *
 *  Created on: Mar 5, 2016
 *      Author: Mario Contreras - marioc@nazul.net
 */

#ifndef COMMON_CONFIG_H_
#define COMMON_CONFIG_H_

// Standard
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

// AR.Drone SDK 2.0.1
#include <ardrone_api.h>
#include <VP_Os/vp_os_signal.h>
#include <VP_Api/vp_api_picture.h>

//Local project
#include "../UI/ardrone_ini.h"


typedef struct _config_ {
	int width;
	int height;
	int exit_required;

	int new_frame;

	vp_os_mutex_t *picture_mutex;
	vp_os_mutex_t *key_mutex;
	vp_os_mutex_t *exit_mutex;

	char addr[19];

	int sock;
	int at_socket;

	int speed;
	int angle;

	int *speed_list;

	int up_pressed;
	int down_pressed;
	int left_pressed;
	int right_pressed;

	void (*manage_gamepad_state)(void);

	int joydev;
	int (* pool_events)(struct _config_ *cfg);

	Controller_info *default_control;
	GList *devices;

	FILE *sample_file;

	int rssi;

	int ihm_curve_alloc_OK;
} config_t;


#endif /* COMMON_CONFIG_H_ */

// EOF
