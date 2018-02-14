/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2018, Open AI Lab
 * Copyright (c) 2018, Linaro Ltd.
 * Author: haitao@openailab.com
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 */

#ifndef __HIKEY960_EXECUTOR_HPP__
#define __HIKEY960_EXECUTOR_HPP__

#include "generic_dev_executor.hpp"


namespace TEngine {

class CPUDevice;

class HIKEY960Executor: public GenericDevExecutor {

public:

	HIKEY960Executor(const dev_id_t& dev_id) {dev_id_=dev_id;}

	void DevGetWorkload(DevWorkload& load) override;	
	bool DevGetPerf(Subgraph * graph,int policy,GraphPerf& perf)override;
	float DevGetFops(Subgraph * graph) override; 
	
	void * DevCreateGraphHandle(Subgraph * graph) override;
	bool DevOptimzeGraph(void * graph_handle) override;
	bool DevPrerun(void * graph_handle) override;
	bool DevRun(void * graph_handle) override;
	bool DevSyncRun(void * graph_handle) override;
	bool DevPostrun(void * graph_handle) override;
	bool DevReleaseGraphHandle(void * graph_handle) override;
	bool DevStart(void) override;
	bool DevStop(void) override;
	
	const dev_id_t& DevGetID(void) override;
	const dev_type_t & DevGetType(void) override;
	
    	dev_status_t DevGetStatus(void) override;
		
	bool Init(void) override;
        bool Release(void) override;

       void UnbindDevice(void) override;
       void BindDevice(Device * ) override;
   
	void SetDevice(CPUDevice * dev) {backend_dev_=dev;}
	CPUDevice * GetDevice(void) {return backend_dev_;}
protected:
	CPUDevice * backend_dev_;
	dev_id_t  dev_id_;
	
};

} //namespace TEngine

#endif
