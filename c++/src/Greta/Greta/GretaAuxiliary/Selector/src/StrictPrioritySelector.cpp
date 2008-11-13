//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : StrictPrioritySelector.cpp
//  @ Date : 22/07/2008
//  @ Author : 
//
//

#include <iostream>
#include "StrictPrioritySelector.h"
#include "AgentBehaviour.h"

StrictPrioritySelector::StrictPrioritySelector() 
{
}

StrictPrioritySelector::StrictPrioritySelector(std::string name, CentralClock *pc) : Selector(name, pc) 
{
	//fid=fopen("time.txt", "w");
}

StrictPrioritySelector::~StrictPrioritySelector() 
{
	//fclose(fid);
}

std::string StrictPrioritySelector::retrieveSignal() {

	//printf("\n\n StrictPrioritySelector::retrieveSignal num_of_elements=%d\n", (int)element.size());
	std::string theEl;
	std::string beh="";

	for ( int i=0; i<element.size(); i++ ) 
	{
		//fprintf(fid, "time: %d  reatTime: %d   %d > %d\n", pc->GetTime(), element[i]->readTime, pc->GetTime() - element[i]->readTime, element[i]->frequency );
		if ( pc->GetTime() - element[i]->readTime > element[i]->frequency )
		{
			
			//element[i]->readTime=pc->GetTime();
			element[i]->ready=true;
		}
		else {
			element[i]->ready=false;
		}
	}
	
	for ( int i=0; i<(int)element.size(); i++ )
	{
		
		if (element[i]->ready)
		{
			if(element[i]->lastEvent != NULL)
			{
				if(element[i]->lastEvent->behaviour!="")
				{
					beh=element[i]->lastEvent->behaviour;
					element[i]->lastEvent->behaviour="";
					element[i]->lastEvent->time=-1;
					element[i]->readTime=pc->GetTime();
					return beh;
				}
			}
			else {
				//printf("Scheduler%d \n",i);
				beh=element[i]->selector->retrieveSignal();
				if (beh.length()!=0)
				{
					element[i]->readTime=pc->GetTime();
					return beh;
				}
				else
					return "";
			}
		}
	}
	return ""; // No signal
}


/*
std::string StrictPrioritySelector::retrieveSignal() {

	//printf("\n\n StrictPrioritySelector::retrieveSignal num_of_elements=%d\n", (int)element.size());
	std::string theEl;
	std::string beh="";

	for ( int i=0; i<element.size(); i++ ) 
	{
		if ( pc->GetTime() - element[i]->readTime > element[i]->frequency )
		{
			element[i]->readTime=pc->GetTime();
			element[i]->ready=true;
		}
		else {
			element[i]->ready=false;
		}
	}
	
	for ( int i=0; i<(int)element.size(); i++ )
	{
		if (element[i]->ready)
		{
			if  ( element[i]->queue != NULL)
			{
				std::vector<AgentBehaviour>::iterator iter;
				
				if ( element[i]->queue->empty()!=1 ) {
					
					beh=element[i]->queue->at(0).behaviour;
					element[i]->queue->erase(element[i]->queue->begin());
					return beh;
				}
				else
				{
					//printf("   SP%d EMPTY\n",i);
				}
			}
			else {
				//printf("Scheduler%d \n",i);
				beh=element[i]->selector->retrieveSignal();
				if (beh.length()!=0 )
					return beh;
				else
					return "";
			}
		}
	}
	return ""; // No signal
}

*/