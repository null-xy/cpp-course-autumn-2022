#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS

// implement a reference counter helper class if you want to


struct restricted_ref_counter
{
    int reference_cnt_;
    restricted_ref_counter(){
        reference_cnt_=1;
    }
};


#endif