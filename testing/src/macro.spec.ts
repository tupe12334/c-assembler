import { readFile } from "fs/promises";

describe("testing macro runner", () => {
  test("testing macro runner", async () => {
    // compare macro.am in examples with macro.am in expectations
    const generatedMacroAm = await readFile("./examples/macro.am", "utf-8");
    const expectedMacroAm = await readFile("./expectations/macro.am", "utf-8");
    expect(generatedMacroAm).toBe(expectedMacroAm);
  });
});
