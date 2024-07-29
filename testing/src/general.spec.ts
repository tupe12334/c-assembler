import { runAssembler } from "./runner";

describe("This testing suite test general error", () => {
  it("should throw error for missing .as file name", async () => {
    const { error } = await runAssembler("");
    expect(error).toBe(10);
  });
  it("should throw error when detects double label declaration", async () => {
    const { error } = await runAssembler("./examples/double_labels");
    expect(error).toBe(11);
  });
});
