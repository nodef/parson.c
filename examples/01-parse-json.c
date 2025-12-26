#define PARSON_IMPLEMENTATION
#include <parson.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  const char *json_string =
      "{\"name\":\"Alice\",\"age\":30,\"skills\":[\"C\",\"Python\"]}";
  JSON_Value *root_value = json_parse_string(json_string);
  if (root_value == NULL) {
    printf("Error parsing JSON string.\n");
    return 1;
  }

  JSON_Object *root_object = json_value_get_object(root_value);
  const char *name = json_object_get_string(root_object, "name");
  double age = json_object_get_number(root_object, "age");
  JSON_Array *skills = json_object_get_array(root_object, "skills");

  printf("Name: %s\n", name);
  printf("Age: %.0f\n", age);
  printf("Skills:\n");
  for (size_t i = 0; i < json_array_get_count(skills); i++) {
    printf("- %s\n", json_array_get_string(skills, i));
  }

  json_value_free(root_value);
  return 0;
}
