#include "TabletModel.h"
#include "Form.h"
TabletModel::TabletModel()
	:levelForms(LEVELS, vector<Form>()){
	formW = 200/ COLS;
	formH = 200/ ROWS;
	reset();
}
void TabletModel::reset() {
	for (int level = 0; level < LEVELS; level++) {
		for (int col = 0; col < COLS; col++) {
			for (int row = 0; row < ROWS; row++) {
				colorField[level][col][row].r = 0;
				colorField[level][col][row].g = 0;
				colorField[level][col][row].b = 0;

			}
			/*
			   vector<Form>::iterator actualForm = levelForms[level].begin();
			   while (actualForm != levelForms[level].end()) {
			   actualForm->reset();
			   }
			 */
		}
	}
}
void TabletModel::addForm(int level, Form form) {
	levelForms[level].push_back(form);
}
Form & TabletModel::form(int level, int n) {
	return levelForms[level][n];
}
Form & TabletModel::lastForm(int level) {
	return levelForms[level][levelForms[level].size() - 1];
}
ColorField & TabletModel::getColorField(){
	return colorField;
}
void TabletModel::update() {
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
		for (unsigned int n = 0; n < levelForms[level].size(); n++) {
			Form &f = levelForms[level][n];
			const Pos    & formPos   = f.getPos();
			const Size   & formSize  = f.getSize();
			const Color  & formColor = f.getColor();
			f.update();
			for(vector<Box>::iterator i= f.boxes.begin();
					i!= f.boxes.end();
					i++){
				Box & box = *i; 
				Pos pos     = formPos   +box.getPos();
				Size size   = formSize  *box.getSize();
				Color color = formColor +box.getColor();
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
