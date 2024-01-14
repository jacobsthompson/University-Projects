#include <iostream>
#include <vector>

#include "App.h"

using namespace std;

int main( int argc, const char* argv[] )
{
	Rect r( 2, 0, 4, 5 );

	vector<AppWindow*> w;

	w.push_back( new CircleWin( 1, 1, 3, 2 ) );
	w.push_back( new CircleWin( r ) );
	w.push_back( new RectWin( 1, 1, 2, 3 ) );
	w.push_back( new RectWin( r ) );

	for( int i = 0; i < w.size(); i++ )
		w[i]->resize( w[i]->get_rect().w, w[i]->get_rect().h * 2 );

	return 0;
}