#include <iostream>
#include <vector>
#include <cassert>
#include "Base.h"
#include "Form.h"
#include "Program.h"
#include "Color.h"
#include "ColorStep.h"
#include "Pos.h"
#include "PosStep.h"
#include "Size.h"
#include "SizeStep.h"
using namespace std;
int main(){
	Program p;
	p.addChange(ColorChange(Color(8,1,10), Color(7,7,4), 9000,3));
	p.addChange(PosChange  (Pos(1,-1),     Pos(4,4),     9990,10));
	p.addChange(SizeChange (Size(1,10),    Size(7,4),    9000,3));

	p.addChange(ColorChange(ColorStep(1,100,-1), 9990,10));
	p.addChange(PosChange  (PosStep(1,-1),       9990,10));
	p.addChange(SizeChange (SizeStep(1,-1),      9990,30));
	Form f;
	while(!p.isFinished()){
		f.update();
		//cout << f;
		//cin.get();
	}
}
