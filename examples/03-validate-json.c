#define PARSON_IMPLEMENTATION
#include <parson.h>
#include <stdio.h>

int main() {
  const char *schema_string = "{\"name\":\"\",\"age\":0}";
  const char *json_string = "{\"name\":\"Charlie\",\"age\":40}";

  JSON_Value *schema = json_parse_string(schema_string);
  JSON_Value *data = json_parse_string(json_string);

  if (json_validate(schema, data) == JSONSuccess) {
    printf("JSON is valid.\n");
  } else {
    printf("JSON is invalid.\n");
  }

  json_value_free(schema);
  json_value_free(data);
  return 0;
}
