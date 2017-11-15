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

#ifndef _RECORDING_H
#define _RECORDING_H

#include <ostream>
#include <string>
#include <vector>

#include "track.h"

const int MAX_NUMBER_OF_TRACKS = 25; //max number of tracks on a recording

class Recording: public data<Track> {
	/*
	Recording represents a musical commercial package of audio tracks
	For example a record album, CD, or single.
	*/
	public:
	Recording(const string & aTitle, 
	          const string & anArtist,
              const string & aProducer,
              const string & aYear,
			  int anId = -1);
	~Recording();
	void removeTrack(Track & aTrack);
	void addTrack(Track & track, int position);
	//vector<Track*> & getTracks();
    string toString() const;
	
	private:
	string title, artist, producer, year;
	Recording(const Recording & aRecording); //hide copy constructor in private section	
};

#endif