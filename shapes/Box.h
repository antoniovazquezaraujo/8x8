#ifndef BOX_H
#define BOX_H
class Box:
	public BasicShape, 
	public PosAnimable, 
	public SizeAnimable, 
	public ColorAnimable, 
	public RotationAnimable {

public:
	Box(Point pos, Size size, Color color)
		:BasicShape(pos, size, color){

	}
	void addPosAnimation();
	void addSizeAnimation();
	void addColorAnimation();
	void addRotationAnimation();

	void update();
	void startAnimations(AnimationType type, int times = -1);
	void startAnimation(AnimationType type, int numChange, int times = -1);
	void stopAnimations(AnimationType type);
	bool isFinished(AnimationType type);
	void nextTurn(AnimationType type);
	void reset(AnimationType type);
	enum AnimationType{ POS, SIZE, COLOR, ROTATION };
};
#endif
