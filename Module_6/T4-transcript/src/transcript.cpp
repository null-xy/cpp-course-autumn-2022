#include "transcript.hpp"
#include <algorithm>
void TranscriptRegistry::Add(const Transcript& trans){
    /*
    std::shared_ptr<Transcript> new_trans = std::make_shared<Transcript>(trans);
    registry_.push_back(new_trans);
    */
    //Transcript new_trans= trans;
    //registry_.push_back(new_trans);
    registry_.push_back(trans);
}

void TranscriptRegistry::RemoveById(const std::string& id){
    /*
    for(std::list<Transcript>::iterator it=registry_.begin(); it!=registry_.end();it++){
        if((*it).student_id==id){
            it=registry_.erase(it);
            it--;
        }
    }
    */
   //for(std::list<std::shared_ptr<Transcript>>::iterator it=registry_.begin(); it!=registry_.end();it++){
   //for(std::list<std::reference_wrapper<Transcript>>::iterator it=registry_.begin(); it!=registry_.end();it++){
        /*
        if((*it).get()->student_id == id){
            it=registry_.erase(it);
            it--;
        }
        
       if((*it).get().student_id == id){
            it=registry_.erase(it);
            it--;
        }
    }*/
    for(std::list<Transcript>::iterator it=registry_.begin(); it!=registry_.end();it++){
        if((*it).student_id==id){
            it=registry_.erase(it);
            it--;
        }
    }
}
/**
std::list<Transcript>::iterator TranscriptRegistry::FindTranscript(const std::string& id){
    std::list<Transcript>::iterator 
    it = std::find_if(registry_.begin(),registry_.end(),[=](const Transcript& trans){
        return (trans.student_id==id);
    });
    if (it != registry_.end())
    {
        return it;
    }
    else{
        return registry_.end();
    }
*/
//std::list<std::shared_ptr<Transcript>>::iterator TranscriptRegistry::FindTranscript(const std::string& id){
//std::list<Transcript>::iterator TranscriptRegistry::FindTranscript(const std::string& id){
//std::list<std::reference_wrapper<Transcript>>::iterator TranscriptRegistry::FindTranscript(const std::string& id){
//std::list<std::reference_wrapper<Transcript>>::iterator TranscriptRegistry::FindTranscript(const std::string& id)
std::list<Transcript>::const_iterator TranscriptRegistry::FindTranscript(const std::string& id) const
{
    //std::list<std::shared_ptr<Transcript>>::iterator 
    //std::list<std::reference_wrapper<Transcript>>::iterator 
    std::list<Transcript>::const_iterator 
    it = std::find_if(registry_.begin(),registry_.end(),[=](const Transcript& trans){
        return (trans.student_id==id);
    });
    if (it != registry_.end())
    {
        return it;
    }else{
        return registry_.end();
    }
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
    /*
    for(std::list<Transcript>::iterator it=registry_.begin(); it!=registry_.end();it++){
        for(std::list<std::pair<std::string, size_t>>::iterator iit=(*it).grades.begin();
        iit!=(*it).grades.end();iit++){
            if ((*iit).first==course)
            {
                id_grades.push_back(std::make_pair((*it).student_id,(*iit).second));
            }
        }
    }
    */
    //for(std::list<std::shared_ptr<Transcript>>::iterator it=registry_.begin(); it!=registry_.end();it++){
    //for(std::list<std::reference_wrapper<Transcript>>::iterator it=registry_.begin(); it!=registry_.end();it++){
        /*
        for(std::list<std::pair<std::string, size_t>>::iterator iit=(*it).get()->grades.begin();
        iit!=(*it).get()->grades.end();iit++){
            if ((*iit).first==course)
            {
                id_grades.push_back(std::make_pair((*it).get()->student_id,(*iit).second));
            }
        }
        
       for(std::list<std::pair<std::string, size_t>>::iterator iit=(*it).get().grades.begin();
        iit!=(*it).get().grades.end();iit++){
            if ((*iit).first==course)
            {
                id_grades.push_back(std::make_pair((*it).get().student_id,(*iit).second));
            }
        }
    }
    */
    return id_grades;
}
/*
std::list<Transcript> TranscriptRegistry::GetTranscripts(){
    return registry_;
}
*/
//std::list<std::shared_ptr<Transcript>> TranscriptRegistry::GetTranscripts(){
//std::list<Transcript> TranscriptRegistry::GetTranscripts(){
//std::list<std::reference_wrapper<Transcript>> TranscriptRegistry::GetTranscripts()
const std::list<Transcript>& TranscriptRegistry::GetTranscripts() const
{
    return registry_;
    /*std::list<Transcript> return_trans;
    for(auto i : registry_){
        return_trans.push_back(*i.get());
    }
    return return_trans;
    */
}