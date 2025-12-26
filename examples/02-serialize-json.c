#define PARSON_IMPLEMENTATION
#include <parson.h>
#include <stdio.h>

int main() {
  JSON_Value *root_value = json_value_init_object();
  JSON_Object *root_object = json_value_get_object(root_value);

  json_object_set_string(root_object, "name", "Bob");
  json_object_set_number(root_object, "age", 25);
  json_object_dotset_string(root_object, "address.city", "New York");
  json_object_dotset_value(root_object, "hobbies",
                           json_parse_string("[\"reading\", \"gaming\"]"));

  char *serialized_string = json_serialize_to_string_pretty(root_value);
  printf("Serialized JSON:\n%s\n", serialized_string);

  json_free_serialized_string(serialized_string);
  json_value_free(root_value);
  return 0;
}
