/* 
 * File:   BSScraper.h
 * Author: s0544768
 *
 * Created on 8. Dezember 2014, 19:28
 */

#ifndef BSSCRAPER_H
#define	BSSCRAPER_H


#include <string>
using namespace std;

class BSScraper {
public:
    static string substringBeweenSeperators(string str, char seperator, int fromSeperator);
    static string toLower(string str);
    
    
};
#endif	/* BSSCRAPER_H */

