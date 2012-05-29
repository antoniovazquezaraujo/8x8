#ifndef COLOR_CHOOSER_LISTENER
#define COLOR_CHOOSER_LISTENER
class ColorChooser;
class ColorChooserListener{
public:
	virtual void accepted(ColorChooser *)=0;
	virtual void canceled(ColorChooser *)=0;
};
#endif
