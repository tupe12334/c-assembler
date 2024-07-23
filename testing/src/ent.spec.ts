import { readFile } from "fs/promises";
import { existsSync } from "fs";

describe("testing entry builder", () => {
  test.each(["ps"])("testing entry builder on %s", async (fileName: string) => {
    const fileExtension = "ent";
    // compare macro.am in examples with macro.am in expectations
    const generatedFile = await readFile(
      `./examples/${fileName}.${fileExtension}`,
      "utf-8"
    );
    const expectedFile = await readFile(
      `./expectations/${fileName}.${fileExtension}`,
      "utf-8"
    );
    expect(generatedFile).toBe(expectedFile);
  });
  it("should not generate .ent file if there is not .entry", () => {
    const fileExists = existsSync(`./examples/several_nums_data.ent`);
    expect(fileExists).toBe(false);
  });
});
