// Note 1: Include the SDK and helpers
#include <osquery/core/system.h>
#include <osquery/sdk/sdk.h>
#include <osquery/sql/dynamic_table_row.h>

using namespace osquery;

// Note 2: Define at least one plugin or table.
class HelloTablePlugin : public TablePlugin {
 private:
  TableColumns columns() const override {
    return {
      std::make_tuple("text_1", TEXT_TYPE, ColumnOptions::DEFAULT),
      std::make_tuple("text_2", TEXT_TYPE, ColumnOptions::DEFAULT),
    };
  }

  TableRows generate(QueryContext& request) {
    TableRows results;

    auto r = make_table_row();
    r["text_1"] = "hello";
    r["text_2"] = "world";

    results.push_back(std::move(r));
    return results;
  }
};

// Note 3: Use REGISTER_EXTERNAL to define your plugin or table.
REGISTER_EXTERNAL(HelloTablePlugin, "table", "hello");

int main(int argc, char* argv[]) {
  // Note 4: Start logging, threads, etc.
  osquery::Initializer runner(argc, argv, ToolType::EXTENSION);

  // Note 5: Connect to osqueryi or osqueryd.
  auto status = startExtension("hello", "0.0.1");
  if (!status.ok()) {
    LOG(ERROR) << status.getMessage();
    runner.requestShutdown(status.getCode());
  }

  // Finally wait for a signal / interrupt to shutdown.
  runner.waitForShutdown();
  return runner.shutdown(0);
}
