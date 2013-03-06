#include <exception>
#include <string>

/* ImageLoadException is an exception which should be 
   thrown when IMG_Load (from SDL_Image) fails to
   load an image. */

class ImageLoadException : public std::exception 
{
private:
	std::string mFilename;

public:
	ImageLoadException( std::string filename ) : 
		exception(),
		mFilename( filename ) {}

	virtual std::string what()
	{
		return mFilename + ": could not open file";
	}
};