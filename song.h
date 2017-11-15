/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								 */
/*  Contributors: Tyler Despatie 101010622			 */
/*  Date:     14-Nov-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _SONG_H
#define _SONG_H

#include <ostream>
#include <string>
#include "Data.h"

class Song: public Data<Song> {
	/*
	Song represents a musical composition (not an audio recording)
	*/
	public:
	Song(const string & aTitle, const string & aComposer, const int anId = -1); 
	~Song(void);
	string getTitle()const;
    string toString() const;	
	private:
	string title;
	string composer;
	Song(const Song & aSong); //hide copy constructor in private section
};

#endif