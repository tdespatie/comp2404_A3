/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								 */
/*  Contributors: Tyler Despatie 101010622			 */
/*  Date:     14-Nov-2017                             */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MYTUNES_H
#define MYTUNES_H
#include <sstream>
#include "UI.h"
#include "command.h"
#include "song.h"
#include "recording.h"
#include "track.h"
#include "user.h"
#include "mytunes_collection.h"

using namespace std;

/*
This is the main application class.
It has knowledge of the UI and data model (not done in this assignment).
*/

class MyTunes
{
  public:
    MyTunes();
    void run();
    void executeCommand(Command cmd);	
  private:
    UI view;
	//Data Model
	//available ID's for app assigned ID's
	//These should only be used after database data has loaded
	int nextAvailableSongID;
	int nextAvailableRecordingID;
	int nextAvailableTrackID;
	//Data collections
	mytunes_collection<Song> songs;
	mytunes_collection<Recording> recordings;
	mytunes_collection<Track> tracks;
	mytunes_collection<User> users;
	
    void executeCMDADD(Command cmd);
    void executeCMDDELETE(Command cmd);
    void executeCMDSHOW(Command cmd);
	
	void executeAddSong(Command cmd);
	void executeAddRecording(Command cmd);
	void executeAddTrack(Command cmd);
	void executeAddUser(Command cmd);
	void executeAddPlaylist(Command cmd);
	void executeAddPlaylistTrack(Command cmd);
	
	void executeDeleteRecording(Command cmd);
	void executeDeleteUser(Command cmd);
    void executeDeleteUserPlaylist(Command cmd);	
    void executeDeleteUserPlaylistTrack(Command cmd);
	void executeDeleteTrack(Command cmd); //cascading delete
	void executeDeleteSong(Command cmd);
	
};
#endif
