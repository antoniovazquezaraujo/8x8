int main(){
	TabletModel model;
	Box b(0,0,3,4);
	b.addPosAnimation(-1, 0, 10, 10);
	b.addRotationAnimation(-90, 10, 10);
	Form f;
	f.addBox(b);
	model.forms.push_back(f);
	while(true){
		model.update();
		//pintar
	}
}
