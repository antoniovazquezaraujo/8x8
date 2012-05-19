#include <MAUtil/Moblet.h>
#include <conprint.h>

#include "MAHeaders.h"

using namespace MAUtil;

/**
 * This example program will divide the screen into four sections, each sections
 * will have a different color. It assumes there are four binary resources which
 * is called RES_SOUND_1 to RES_SOUND_4 which contains small audio files. The
 * resources needs to be defined as .ubin or .bin in the resource .lst or .lstx
 * file.   
 *
 * When pressing either of these four sections a corresponding sound will play.    
 *
 */    
class MyMoblet : public Moblet
{
public:

    MyMoblet()
    {
        // Checking the size of the screen
        int mWindowWidth = EXTENT_X(maGetScrSize());
        int mWindowHeight = EXTENT_Y(maGetScrSize());

        // Divide the screen in four sections
        // and render each in different colors
        mCenterX = mWindowWidth/2;
        mCenterY = mWindowHeight/2;

        maSetColor(0xff00ff);
        maFillRect(0, 0, mCenterX, mCenterY);

        maSetColor(0xffff00);
        maFillRect(mCenterX, 0, mCenterX, mCenterY);

        maSetColor(0x00ffff);
        maFillRect(0, mCenterY, mCenterX, mCenterY);

        maSetColor(0xff0000);
        maFillRect(mCenterX, mCenterY, mCenterX, mCenterY);

        maUpdateScreen();

        // Init the sounds and send a panic if it failed
        if (!initSounds())
            maPanic(-1, "Couldn't initiate sound resources");

    }

    bool initSounds()
    {
        // MoSync resources are created in increasing order which
        // means that you can use the first resource handle as
        // a base and then access each resource by incrementing
        // an offset.
        for(int i = 0; i < 4; i++)
        {
            // Create a maAudioData handle from the resource
            mData[i] = maAudioDataCreateFromResource(
                    NULL,
                    (RES_SOUND_1+i),
                    0,
                    maGetDataSize((RES_SOUND_1+i)),
                    0);
            // If the maAudioData handle is less then 0 it failed
            if(mData[i] < 0)
                return false;

            // Create a maAudioInstance handle from the audio data.
            // The instance is then used when playing the audio.
            mInstance[i] = maAudioInstanceCreate(mData[i]);

            // If the maAudioInstance handle is less then 0 it failed
            if(mInstance[i] < 0)
                return false;
        }

        return true;
    }

    /**
     * This program only checks for the back and menu key,
     * and when either of those are pressed the application
     * will close. This will only happen on Android.
    */
    void keyPressEvent(int keyCode, int nativeCode)
    {
        if (MAK_BACK == keyCode || MAK_MENU == keyCode)
        {
            close();
        }
    }


    /**
     * Checks each key press on the screen and plays a sound according
     * to which quadrant of the screen which was pressed.
     * The touchid will be ignored, it's too identify which multitouch
     * event which was fired. For this test a sound will play on each
     * touch so it can handle multiple sounds at the same time. When
     * a sound is playing and that screen section is touched again, that
     * sound will restart meaning that all four samples will be able to 
     * play at the same time, but only one instance of each.    
     */
    virtual void multitouchPressEvent(MAPoint2d p, int touchId)
    {
        // Quickly check which section on the screen is pressed
        // by comparing the point event coordinates against the
        // the center of the screen.   
        int index;
        if(p.y > mCenterY)
        {
            if(p.x > mCenterX)
                index = 0;
            else
                index = 1;
        }
        else
        {
            if(p.x > mCenterX)
                index = 2;
            else
                index = 3;
        }

        // Stops the sound if this instance was already playing,
        // if it's not playing nothing will happen. 
        maAudioStop(mInstance[index]);
        // Rewinds the instance to the start of the sound
        maAudioSetPosition(mInstance[index], 0);
        // Plays the sound
        maAudioPlay(mInstance[index]);

    }

    // Ignored in this example 
    virtual void multitouchMoveEvent(MAPoint2d p, int touchId)
    {}

    // Ignored in this example 
    virtual void multitouchReleaseEvent(MAPoint2d p, int touchId)
    {}

    // Ignored in this example 
    void keyReleaseEvent(int keyCode, int nativeCode)
    {}

    // Ignored in this example 
    void pointerPressEvent(MAPoint2d point)
    {}

    // The center of the screen, calculated at start up 
    int mCenterX;
    int mCenterY;

    // The four audio data handles 
    MAAudioData mData[4];
    // The four audio instance handles 
    MAAudioInstance mInstance[4];
};


extern "C" int MAMain()
{
    Moblet::run(new MyMoblet());
    return 0;
}
