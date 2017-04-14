/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkMyElevationFilter.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkMyElevationFilter.h"

#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkMyElevationFilter);

//----------------------------------------------------------------------------
vtkMyElevationFilter::vtkMyElevationFilter()
{
}

//----------------------------------------------------------------------------
vtkMyElevationFilter::~vtkMyElevationFilter()
{
}

/*****************************************************************************
* This method responds to the request made by vtk Pipeleine. 
* This method is invoked when the time stamp is changed from paraview VCR.
*****************************************************************************/
int vtkMyElevationFilter::RequestData(vtkInformation *vtkNotUsed(request),vtkInformationVector **vtkNotUsed(inputVector),	vtkInformationVector *outputVector){

	vtkInformation *Node_Mesh = outputVector->GetInformationObject(0);
	Node_Mesh->Print(std::cout);



	// // Get Current Time;
 //  	this->Node_Mesh_Current_Time = Time_Map.find( Node_Mesh->Get(vtkStreamingDemandDrivenPipeline::UPDATE_TIME_STEP()))->second;

	// piece_no = Node_Mesh->Get(vtkStreamingDemandDrivenPipeline::UPDATE_PIECE_NUMBER());
	// num_of_pieces = Node_Mesh->Get(vtkStreamingDemandDrivenPipeline::UPDATE_NUMBER_OF_PIECES());

	// // cout << "piece_no " << piece_no <<endl;
	// // cout << "num_of_pieces " << num_of_pieces << endl;
	// // cout << "Node_Mesh_Current_Time " << Node_Mesh_Current_Time <<endl;

	// int start =-1;
	// int end   =0;
	// if(single_file_visualization_mode){
	// 	if(piece_no>0)
	// 		return 1;
	// }
	// else{
	// 	start = piece_no*ceil(((double)Number_of_Processes_Used)/((double)num_of_pieces));
	// 	end   = start +ceil(((double)Number_of_Processes_Used)/((double)num_of_pieces));
	// 	end = end > (Number_of_Processes_Used-1) ? Number_of_Processes_Used-1:end; 
	// }

	// // cout << "Start " << start <<endl;
	// // cout << "End "   << end << endl;

	// for (int i = start; i<end; i++){

	// 	this->domain_no = i;
	// 	Domain_Initializer(domain_no);

	// 	// cout << "domain_no " << domain_no << endl;;

	// 	if (!Whether_Node_Mesh_build[domain_no]){

	// 		UGrid_Node_Mesh[domain_no]         = vtkSmartPointer<vtkUnstructuredGrid>::New();
	// 		UGrid_Current_Node_Mesh[domain_no] = vtkSmartPointer<vtkUnstructuredGrid>::New();

	// 		this->Get_Node_Mesh(UGrid_Node_Mesh[domain_no]);
	// 	}

	// 	UGrid_Current_Node_Mesh[domain_no]->ShallowCopy(UGrid_Node_Mesh[domain_no]);

	//   	// int Clength = outInfo->Length(vtkStreamingDemandDrivenPipeline::TIME_STEPS());
	//   	// double* Csteps = outInfo->Get(vtkStreamingDemandDrivenPipeline::TIME_STEPS());

	// 	// ///////////////////////////////  Printing For Debugging ////////////////////////////////
	// 	// cout << "Number of Nodes "   << " " << Number_of_Nodes << endl;
	// 	// cout << "Pseudo_Number_of_Nodes "  << " " << Pseudo_Number_of_Nodes << endl;
	// 	// cout << "Number of Gauss Points " << Number_of_Gauss_Nodes << endl;
	// 	// cout << "Number of Elements "   << " " << Number_of_Elements << endl;
	// 	// cout << "Pseudo_Number_of_Elements"  << " " << Pseudo_Number_of_Elements << endl;
	// 	// ///////////////////////////////////////////////////////////////////////////////////////

	// 	if(eigen_mode_on){
	// 		Build_Eigen_Modes_Node_Attributes(UGrid_Current_Node_Mesh[domain_no], this->Node_Mesh_Current_Time );	
	// 	}

	// 	else{
	// 		Build_Node_Attributes(UGrid_Current_Node_Mesh[domain_no], this->Node_Mesh_Current_Time );
	// 		if(Enable_Gauss_To_Node_Interpolation_Flag) Build_Stress_Field_At_Nodes(UGrid_Current_Node_Mesh[domain_no], this->Node_Mesh_Current_Time);
	// 	}
		

	// // 	// /*************************************************************************************************************************************/
	// // 	// /****************************************************** if Gauss Mesh is Enabled *****************************************************/
	// // 	// if(Enable_Gauss_Mesh){

	// // 	// 	vtkInformation *Gauss_Mesh = outputVector->GetInformationObject(1);

	// // 	// 	if (!Whether_Gauss_Mesh_build[domain_no] ){ 
	// // 	// 		UGrid_Gauss_Mesh[domain_no] = vtkSmartPointer<vtkUnstructuredGrid>::New();
	// // 	// 		this->Get_Gauss_Mesh(UGrid_Gauss_Mesh[domain_no]);
	// // 	// 		UGrid_Current_Gauss_Mesh->ShallowCopy(UGrid_Gauss_Mesh[domain_no]);
	// // 	// 	} 

	// // 	// 	this->Gauss_Mesh_Current_Time = Time_Map.find( Gauss_Mesh->Get(vtkStreamingDemandDrivenPipeline::UPDATE_TIME_STEP()))->second;
	// // 	//   	if(Gauss_Mesh_Current_Time > Number_Of_Time_Steps){
	// // 	//   		Gauss_Mesh_Current_Time =0;
	// // 	//   	}

	// // 	//   	Build_Gauss_Attributes(UGrid_Current_Gauss_Mesh, this->Gauss_Mesh_Current_Time );
	// // 	//   	vtkUnstructuredGrid *Output_Gauss_Mesh = vtkUnstructuredGrid::SafeDownCast(Gauss_Mesh->Get(vtkDataObject::DATA_OBJECT()));
	// // 	//   	Output_Gauss_Mesh->ShallowCopy(UGrid_Current_Gauss_Mesh);
	// // 	// }
	// // 	// /***************************************************************************************************************************************/
	// // 	// /***************************************************************************************************************************************/	
	// }

	// vtkSmartPointer<vtkUnstructuredGrid>  Chunk_Node_mesh =  vtkSmartPointer<vtkUnstructuredGrid>::New();;

	// if(single_file_visualization_mode){
	// 	Chunk_Node_mesh->ShallowCopy(UGrid_Current_Node_Mesh[0]);
	// }
	// else{
	// 	Merge_Mesh(start,end, Chunk_Node_mesh);
	// }

	// // get the ouptut pointer to paraview 
	vtkUnstructuredGrid *Output_Node_Mesh = vtkUnstructuredGrid::SafeDownCast(Node_Mesh->Get(vtkDataObject::DATA_OBJECT()));

	Output_Node_Mesh->ShallowCopy(UGrid_Node_Mesh);


	return 1;
}

// ****************************************************************************
// * This method is called only once for information about time stamp and extent. 
// * This is the method which is called firt after the default constructor is 
// * initialized
// ****************************************************************************

int vtkMyElevationFilter::RequestInformation( vtkInformation *request, vtkInformationVector **inVec, vtkInformationVector* outVec){

  vtkInformation *inInfo = inVec[0]->GetInformationObject(0);
UGrid_Node_Mesh = vtkUnstructuredGrid::SafeDownCast(inInfo->Get(vtkDataObject::DATA_OBJECT()));

	// cout <<inInfo->Get(vtkDataObject::DATA_OBJECT())->GetFileName();

	// UGrid_Node_Mesh  = vtkUnstructuredGrid::SafeDownCast((outVec->GetInformationObject(0))->Get(vtkDataObject::DATA_OBJECT())); cout << "ok " << endl;
	UGrid_Node_Mesh->Print(std::cout);

	// this->Initialize();

	// vtkInformation* Node_Mesh = outVec->GetInformationObject(0);

	// double Time_range[2]={Time[0],Time[Number_of_Time_Steps-1]};

	// Node_Mesh->Set(vtkStreamingDemandDrivenPipeline::TIME_STEPS(),Time, this->Number_of_Time_Steps);
	// Node_Mesh->Set(vtkStreamingDemandDrivenPipeline::TIME_RANGE(),Time_range,2);
	// Node_Mesh->Set(CAN_HANDLE_PIECE_REQUEST(), 1);

	// ***********************************************************************************************************************************
	// /****************************************************** if Gauss Mesh is Enabled *****************************************************/
	// if(Enable_Gauss_Mesh){

	// 	vtkInformation* Gauss_Mesh = outVec->GetInformationObject(1);

	// 	Gauss_Mesh->Set(vtkStreamingDemandDrivenPipeline::TIME_STEPS(),Time, this->Number_of_Time_Steps);
	// 	Gauss_Mesh->Set(vtkStreamingDemandDrivenPipeline::TIME_RANGE(),Time_range,2);

	// 	Gauss_Mesh->Set(CAN_HANDLE_PIECE_REQUEST(), 1);
	// }

	/************************************************************************************************************************************/

	return 1;
}

//----------------------------------------------------------------------------
void vtkMyElevationFilter::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
