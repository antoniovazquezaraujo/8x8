#include "Page.h"
#include "Form.h"
Page::Page()
	:levels(LEVELS, vector<int>()){
	formW = 200/ COLS;
	formH = 200/ ROWS;
	reset();
}
Page::~Page(){
	for(vector<Form*>::iterator i = forms.begin();
			i != forms.end(); 
			i++){
		delete *i;
	}
}
void Page::reset() {
	for (int level = 0; level < LEVELS; level++) {
		for (int col = 0; col < COLS; col++) {
			for (int row = 0; row < ROWS; row++) {
				colorField[level][col][row].r = 0;
				colorField[level][col][row].g = 0;
				colorField[level][col][row].b = 0;

			}
		}
	}
}
void Page::addForm(string name, int level, Form form*) {
	forms.push_back(form);
	int formKey = forms.size()-1; 
	namesToForms[name] = formKey; 
	levels[level].push_back(formKey);
	formsToLevels[formKey]=level;
}
Form * Page::getForm(string name){
	return forms[namesToForms[name]];
}
vector<Form*> Page::getFormsAt(Pos pos){
	// ordenar esto por NIVEL!!
	vector<Form*> ret;
	for(vector<Form*>::iterator i = forms.begin();
			i != forms.end(); 
			i++){
		if(i->containsBoxAt(pos)){
			ret.push_back((*i));
		}
	}
	return ret;
}
ColorField & Page::getColorField(){
	return colorField;
}
void Page::update() {
	for (int level = 0; level < LEVELS; level++) {
		for (int col = 0; col < COLS; col++) {
			for (int row = 0; row < ROWS; row++) {
				colorField[level][col][row].r = 0;
				colorField[level][col][row].g = 0;
				colorField[level][col][row].b = 0;
			}
		}
	}
	for (int level = 0; level < LEVELS; level++) {
		for (unsigned int n = 0; n < levels[level].size(); n++) {
			Form *f = forms[levels[level][n]];
			const Pos    & formPos   = f->getPos();
			const Size   & formSize  = f->getSize();
			const Color  & formColor = f->getColor();
			f->update();
			for(vector<Box>::iterator i= f->boxes.begin();
					i!= f->boxes.end();
					i++){
				Box & box = *i; 
				Pos pos     = formPos   +box.getPos();//Pos de la caja + origen del form
				Size size   = formSize  *box.getSize();//Size * size del form !!
				Color color = formColor +box.getColor();//Color + el del form??
				for (int col = pos.x; col < pos.x + size.w; col++) {
					for (int row = pos.y; row < pos.y + size.h; row++) {
						if(col >= 8 || col < 0 || row >= 8 || row < 0) continue;
						colorField[level][col][row].r = color.r;
						colorField[level][col][row].g = color.g;
						colorField[level][col][row].b = color.b;
					}
				}
			}
		}
	}
}
