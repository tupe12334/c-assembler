import { readFile } from "fs/promises";
import { existsSync } from "fs";

describe("testing external builder", () => {
  test.each(["ps"])(
    "testing externals builder on %s",
    async (fileName: string) => {
      const fileExtension = "ext";
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
    }
  );
  it("should not generate .ext file if there is not .external", () => {
    const fileExists = existsSync(`./examples/several_nums_data.ext`);
    expect(fileExists).toBe(false);
  });
});
