#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS

// implement a reference counter helper class if you want to


class Restricted_ref_counter
{
    public:
    void SetRef(){
        reference_cnt_=1;
    }
    void AddRef(){
        (this->reference_cnt_)++;
    }
    void RemoveRef(){
        (this->reference_cnt_)--;
    }
    int GetRefCnt(){
        return (this->reference_cnt_);
    }
    private:
    int reference_cnt_;
};


#endif