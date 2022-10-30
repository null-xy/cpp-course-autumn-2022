#include "transcript.hpp"
#include <algorithm>
void TranscriptRegistry::Add(const Transcript& trans){
    this->registry_.push_back(trans);
}
void TranscriptRegistry::RemoveById(const std::string& id){
    for(std::list<Transcript>::iterator it=registry_.begin(); it!=registry_.end();it++){
        if((*it).student_id==id){
            it=registry_.erase(it);
            it--;
        }
    }
}
std::list<Transcript>::iterator TranscriptRegistry::FindTranscript(const std::string& id){
    
    std::list<Transcript>::iterator 
    it = std::find_if(registry_.begin(),registry_.end(),[=](const Transcript& trans){
        return (trans.student_id==id);
    });
    if (it != registry_.end())
    {
        return it;
    }
    /*else{
        return registry_.end();
    }*/
}
//returns a list of pairs of student ids and course
//std::list<std::pair<std::string, size_t>> grades; 
/**< List of (course, grade) pairs */
//return student id and thier grades
std::list<std::pair<std::string, size_t>> TranscriptRegistry::FindCourseResults(const std::string& course){
    std::list<std::pair<std::string, size_t>> id_grades;
    for(std::list<Transcript>::iterator it=registry_.begin(); it!=registry_.end();it++){
        for(std::list<std::pair<std::string, size_t>>::iterator iit=(*it).grades.begin();
        iit!=(*it).grades.end();iit++){
            if ((*iit).first==course)
            {
                id_grades.push_back(std::make_pair((*it).student_id,(*iit).second));
            }
            
        }
    } 
    return id_grades;
}

std::list<Transcript> TranscriptRegistry::GetTranscripts(){
    return registry_;
}