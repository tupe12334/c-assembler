import { readFile } from "fs/promises";

describe("testing external builder", () => {
  test.each(["ps"])(
    "testing object builder on %s",
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
});
