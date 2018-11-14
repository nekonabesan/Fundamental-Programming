require __dir__ + "/spec_helper"
require __dir__ + '/../app/model/buffer.rb'


describe "演習 3" do
  context "Buffer" do
    obj = Buffer.new
    it "insert('abc')" do
      obj.insert("abc")
      obj.top
      results = obj.print.to_s
      expect(results).to match("abc")
    end
    it "insert('def')" do
      obj.insert('def')
      results = obj.print.to_s
      expect(results).to match("abc")
    end
    it "top->print" do
      obj.top
      results = obj.print.to_s
      expect(results).to match("def")
    end
    it "inset('ghi')" do
      obj.insert('ghi')
      obj.top
      results = obj.print.to_s
      expect(results).to match("ghi")
    end
    it "forward" do
      obj.forward
      results = obj.print.to_s
      expect(results).to match("def")
    end
    it "forward" do
      obj.forward
      results = obj.print.to_s
      expect(results).to match("abc")
    end
    it "forward" do
      obj.forward
      results = obj.print.to_s
      expect(results).to match("EOF")
    end
    it "a" do
      obj.top
      results = obj.a
      expect(results).to eq true
    end
    it "print" do
      obj.top
      result = obj.print.to_s
      expect(result).to match('def')
    end
  end
  context "a" do
    obj = Buffer.new
    obj.insert('abc')
    obj.insert('def')
    obj.insert('ghi')
    obj.top
    it "a" do
      results = obj.a
      expect(results).to eq true
    end
    it "print" do
      obj.top
      results = obj.print.to_s
      expect(results).to match('def')
    end
    it "a" do
      results = obj.a
      expect(results).to eq true
    end
    it "a" do
      obj.top
      results = obj.a
      expect(results).to eq true
    end
    it "a" do
      obj.top
      results = obj.a
      expect(results).to match("EOF")
    end
  end
  context "b" do
    obj = Buffer.new
    obj.insert('abc')
    obj.insert('def')
    obj.insert('ghi')
    obj.top
    it "b" do
      results = obj.print.to_s
      expect(results).to match('abc')
    end
    it "b" do
      obj.b
      results = obj.print.to_s
      expect(results).to match('def')
    end
    it "b" do
      obj.forward
      obj.forward
      results = obj.print.to_s
      expect(results).to match('ghi')
    end
    it "b" do
      results = obj.b
      expect(results).to match('EOF')
    end
  end
  context "c" do
    obj = Buffer.new
    obj.insert('abc')
    obj.insert('def')
    obj.insert('ghi')
    obj.top
    it "c" do
      obj.c
      results = obj.print.to_s
      expect(results).to match("abc")
    end
    it "c" do
      obj.forward
      obj.c
      results = obj.print.to_s
      expect(results).to match("abc")
    end
    it "c" do
      obj.forward
      obj.forward
      obj.c
      results = obj.print.to_s
      expect(results).to match("def")
    end
    it "c" do
      obj.forward
      obj.forward
      obj.c
      results = obj.print.to_s
      expect(results).to match("ghi")
    end
    it "c" do
      obj.forward
      obj.c
      results = obj.print.to_s
      expect(results).to match("ghi")
    end
  end
  context "d" do
    obj = Buffer.new
    obj.insert('abc')
    obj.insert('def')
    obj.insert('ghi')
    it "d" do
      obj.d
      results = obj.print.to_s
      expect(results).to match('ghi')
    end
    it "d" do
      obj.forward
      results = obj.print.to_s
      expect(results).to match('def')
    end
    it "d" do
      obj.forward
      results = obj.print.to_s
      expect(results).to match('abc')
    end
    it "d" do
      obj.forward
      results = obj.print.to_s
      expect(results).to match('EOF')
    end
  end
end
