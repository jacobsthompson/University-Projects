#include <iostream>
#include "Vec.h"
#include "Rect.h"
#include <vector>

using namespace std;

int main(){
	//floats for x, y, width, height, and a Rect vector vr for storing Rects
	float x,y,w,h;
	vector<Rect> vr;

	//take in x y w h until all values inputted are negative
	cout << "Type 4 floats to define a rectangle: ";
	cin >> x >> y >> w >> h;
	while(x >= 0 || y >= 0 || w >= 0 || h >= 0){
		//add the new rect to the vector
		vr.push_back(Rect(x,y,w,h));
		//take in a new input
		cout << "Type 4 floats to define a rectangle: ";
		cin >> x >> y >> w >> h;
	}

	//take in an x y for the point in vector space until both p1 and p2 are -99
	float p1, p2;
	cout << "Type 2 floats to define a point: ";
	cin >> p1 >> p2;
	while(p1 != -99 && p2 != -99){
		//loop through every rect in the vr vector
		for(int i = 0; i < vr.size(); i++){
			//check if the point (p1,p2) is in the bounds of the rect i
			if(vr[i].contains(Vec(p1,p2)) == true){
				//if it is print inside
				cout << "The point is INSIDE of rectangle " << i << endl;
			} else {
				//if not print outside
				cout << "The point is OUTSIDE of rectangle " << i << endl;
			}
		}
		//take in new input
		cout << "Type 2 floats to define a point: ";
		cin >> p1 >> p2;
	}
	cout << "Finished!" << endl;
	return 0;
}