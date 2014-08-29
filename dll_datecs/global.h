#define MAX_TYPE_COUNT 255
#define MAX_CHAN_COUNT_OF_SOME_TYPE 255

struct field_data
{
  Variant var;
  AnsiString name;
};

struct database_chan_params
{
  field_data *params;
  unsigned int count;
};

struct database_types
{
  database_chan_params *chan;
  unsigned int param_type;
  AnsiString name;
  unsigned int count;
};

struct func_param_description
{
 
  int *param1;
  database_chan_params *param2;
  int result;
  AnsiString string;
};



