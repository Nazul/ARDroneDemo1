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
 * navdata.h
 *
 *  Created on: Mar 5, 2016
 *      Author: Mario Contreras - marioc@nazul.net
 */

#ifndef NAVDATA_NAVDATA_H_
#define NAVDATA_NAVDATA_H_

// AR.Drone SDK 2.0.1
#include <ardrone_tool/Navdata/ardrone_navdata_client.h>

PROTO_THREAD_ROUTINE(demo_navdata_client_init, data);
PROTO_THREAD_ROUTINE(demo_navdata_client_process, data);
PROTO_THREAD_ROUTINE(demo_navdata_client_release, data);


#endif /* NAVDATA_NAVDATA_H_ */

// EOF
