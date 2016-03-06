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
 * ardrone_ini.h
 *
 *  Created on: Mar 5, 2016
 *      Author: Mario Contreras - marioc@nazul.net
 */

#ifndef UI_ARDRONE_INI_H_
#define UI_ARDRONE_INI_H_

// OS (Linux)
#include <libudev.h>
#include <linux/joystick.h>

// glib-2.0
#include <glib.h>

// Standard
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/ioctl.h>

// libxml2
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>
#include <libxml/xmlreader.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

// AR.Drone SDK 2.0.1
#include <ardrone_tool/UI/ardrone_input.h>

#define FILENAME "ardrone.xml"

enum { NONE = 0, AXIS, HAT, BUTTON };

enum {
	START = 0,
	EMERGENCY,
	PITCH_FRONT,
	PITCH_BACK,
	ROLL_LEFT,
	ROLL_RIGHT,
	YAW_LEFT,
	YAW_RIGHT,
	SPEED_UP,
	SPEED_DOWN,
	NUM_COMMAND
};

typedef struct {
	int value;
	int type;
} Control_Type;

extern input_device_t control_device;

C_RESULT open_control_device(void);
C_RESULT update_control_device(void);
C_RESULT close_control_device(void);

typedef struct {
	int num_axis;
	int num_buttons;
	gchar *name;
	gchar *filename;
	int32_t serial;
	gboolean def;
	gboolean config;
	Control_Type commands[NUM_COMMAND];
} Controller_info;

extern Controller_info *control;
extern Controller_info *default_control;
extern GList *devices;

gboolean search_devices(GList **list_controllers);
void create_ini();
void load_ini();
void save_init(Controller_info *def);


#endif /* UI_ARDRONE_INI_H_ */

// EOF
