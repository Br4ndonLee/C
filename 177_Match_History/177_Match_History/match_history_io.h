//
//  match_history_io.h
//  177_Match_History
//
//  Created by Brandon on 2022/02/17.
//

#ifndef match_history_io_h
#define match_history_io_h

void write_match_history(char* buffer, size_t buffer_size, const char* names[], const int wins[], const int losses[], const float kills[], const float deaths[], const float assists[], size_t count);
void read_match_history(char* buffer);

#endif /* match_history_io_h */
