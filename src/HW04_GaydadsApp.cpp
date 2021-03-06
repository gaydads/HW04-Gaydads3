#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "HW04_GaydadsApp.h"
#include "Starbucks.h"
#include "GaydadsStarbucks.h"
#include "cinder/Rand.h"
#include <fstream>
#include <cstdlib>

using namespace ci;
using namespace ci::app;
using namespace std;

Entry* HW04_GaydadsApp::readFile(){
	string line;
	double x, y;
	ifstream myFile("Starbucks_2006.csv");
	int numItems = 7655;
	

	Entry* arr = new Entry[numItems];
	for(int i = 0; i < numItems; i++){
		getline(myFile, line, ',');
		arr[i].identifier = line;
		getline(myFile, line, ',');
		x = atof(line.c_str());
		arr[i].x = x;
		getline(myFile, line, '\r');
		y = atof(line.c_str());
		arr[i].y = y;
	}
	return arr;
}

void HW04_GaydadsApp::setup()
{
	structure = new gaydadsStarbucks();
	Entry* AllStarbucks = readFile();
	Entry* location;
	
	structure->build(AllStarbucks,7655);
	
	location = structure->getNearest(.5,.5);
	HW04_GaydadsApp::console() <<location->identifier <<std::endl;
}

void HW04_GaydadsApp::mouseDown( MouseEvent event )
{
}

void HW04_GaydadsApp::update()
{
}

void HW04_GaydadsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04_GaydadsApp, RendererGl )
