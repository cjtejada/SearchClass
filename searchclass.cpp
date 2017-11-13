#include "searchclass.h"

SearchClass::SearchClass(QObject *parent) : QObject(parent)
{

}
QStringList SearchClass::getFilenameAndInput(QString inputString){

    m_resultList.clear();

    QStringList fileNameList = getFileName();
    QStringList tempResultList;

    QString filename, tempFilename, temp, resultToCompare;

    int j = 0;

    for (int i = 0; i < fileNameList.size(); i++){

        filename = fileNameList[i];
        temp = CompareInputAndFilename(inputString, filename);

        if(temp != "FILE NOT FOUND"){
            tempResultList.append(temp);
            j++;
        }
    }

    j = 0;
    int i = 0, k = 0;

    while(!tempResultList.empty()){

        if(i == -1)
            i = 0;

        tempFilename = tempResultList[i];

        for(int i = 0; i < inputString.length(); i++)
            resultToCompare[i] = tempFilename[k], k++;

        if(tempResultList.last() == tempResultList[i])
                j++,i = -1;
        i++;
        k = j;

        if(tempResultList.size() == 1){
            m_resultList.append(tempFilename);
            tempResultList.removeOne(tempFilename);
            break;
        }
        if(inputString.toLower() == resultToCompare.toLower() || tempResultList.size() == 1){
            m_resultList.append(tempFilename);
            tempResultList.removeOne(tempFilename);
            i = i - 1;
        }
    }
    return m_resultList;
}

QString SearchClass::CompareInputAndFilename(QString inputString, QString filename){

    int j = 0;
    QString msg_NOT_FOUND = ("FILE NOT FOUND");

    if((inputString.length() <= filename.length()) || inputString == ""){
        for(int i = 0; i < inputString.length(); i++){
            while(inputString[i].toLower() != filename[j].toLower()){
                if(i > 0)
                    i = 0;
                j++;
                if(j > filename.length()) {
                    return msg_NOT_FOUND;
                }
            }
            j++;
        }
        return filename;
    }
    return msg_NOT_FOUND;
}

QStringList SearchClass::getFileName(){

    QStringList m_printNames;

    m_printNames.append("Alabama");
    m_printNames.append("Alaska");
    m_printNames.append("Arizona");
    m_printNames.append("Arkansas");
    m_printNames.append("California");
    m_printNames.append("Colorado ");
    m_printNames.append("Connecticut");
    m_printNames.append("Delaware");
    m_printNames.append("Florida");
    m_printNames.append("Georgia");
    m_printNames.append("Hawaii");
    m_printNames.append("Idaho");
    m_printNames.append("Illinois");
    m_printNames.append("Indiana");
    m_printNames.append("Iowa");
    m_printNames.append("Kansas");
    m_printNames.append("Kentucky ");
    m_printNames.append("Louisiana");
    m_printNames.append("Maine");
    m_printNames.append("Maryland");
    m_printNames.append("Massachusetts");
    m_printNames.append("Michigan");
    m_printNames.append("Minnesota");
    m_printNames.append("Mississippi");
    m_printNames.append("Missouri");
    m_printNames.append("Montana");
    m_printNames.append("Nebraska");
    m_printNames.append("Nevada");
    m_printNames.append("New Hampshire");
    m_printNames.append("New Jersey");
    m_printNames.append("New Mexico");
    m_printNames.append("New York");
    m_printNames.append("North Carolina");
    m_printNames.append("North Dakota");
    m_printNames.append("Ohio");
    m_printNames.append("Oklahoma");
    m_printNames.append("Oregon");
    m_printNames.append("Pennsylvania");
    m_printNames.append("Rhode Island");
    m_printNames.append("South Carolina");
    m_printNames.append("South Dakota");
    m_printNames.append("Tennessee");
    m_printNames.append("Texas");
    m_printNames.append("Utah");
    m_printNames.append("Vermont");
    m_printNames.append("Virginia ");
    m_printNames.append("Washington");
    m_printNames.append("West Virginia");
    m_printNames.append("Wisconsin");
    m_printNames.append("Wyoming");
    m_printNames.append("West_Virginia");
    m_printNames.append("NorthCarolina");
    m_printNames.append("South.Carolina");
    m_printNames.append(" Illinois");
    m_printNames.append("South  Dakota");
    m_printNames.append("123New York");
    m_printNames.append("TeXa$");
    m_printNames.append("Minnesota...");
    m_printNames.append("NEBR@SKA");
    m_printNames.append("__Connecticut");
    m_printNames.append("_Ohio");
    m_printNames.append("Washington__");
    m_printNames.append("###Missouri");
    m_printNames.append("South Dakota!");
    m_printNames.append("SouthD@kot@!");
    m_printNames.append("Cali");
    m_printNames.append("!!!Colorado");
    m_printNames.append("Connecticut+++");
    m_printNames.append("Del@ware");
    m_printNames.append("Florid@!");
    m_printNames.append("GeoRG!@");
    m_printNames.append("Hawa!!");
    m_printNames.append("(Idaho)");
    m_printNames.append("Illinoi$");
    m_printNames.append("Indi@n@");

    return m_printNames;
}
