require __dir__ + "/spec_helper"
require __dir__ + '/../fp10_01.rb'


describe "演習 1" do
  context "listsum" do
    it "listsum(10)" do
      results = listsum(10)
      expect(results).to eq 55
    end
    it "listsum(100)" do
      results = listsum(100)
      expect(results).to eq 5050
    end
    it "listsum(22)" do
      results = listsum(22)
      expect(results).to eq 253
    end
    it "listsum(nil)" do
      results = listsum(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "b" do
    it "b('stirng')" do
      results = b('string')
      expect(results).to match("string")
    end
    it "b('Hallo World!!')" do
      results = b('Hallo World!!')
      expect(results).to match("Hallo World!!")
    end
    it "b('0123456789')" do
      results = b('0123456789')
      expect(results).to match("0123456789")
    end
    it "b(nil)" do
      results = b(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "listcatrev" do
    it "" do
      results = listcatrev("string")
      expect(results).to match("gnirts")
    end
    it "" do
      results = listcatrev('Hallo World!!')
      expect(results).to match("!!dlroW ollaH")
    end
    it "" do
      results = listcatrev('0123456789')
      expect(results).to match("9876543210")
    end
    it "c(nil)" do
      results = listcatrev(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "printmany" do
    it "printmany('string')" do
      results = printmany("string")
      expect(results).to match("sttrrriiiinnnnngggggg")
    end
    it "printmany('Hallo World!!')" do
      results = printmany("Hallo World!!")
      expect(results).to match("Haalllllllooooo      WWWWWWWoooooooorrrrrrrrrllllllllllddddddddddd!!!!!!!!!!!!!!!!!!!!!!!!!")
    end
    it "printmany('0123456789')" do
      results = printmany("0123456789")
      expect(results).to match("0112223333444445555556666666777777778888888889999999999")
    end
    it "" do
      results = printmany(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "listoddsum" do
    it "listoddsum(string)" do
      results = listoddsum("string")
      expect(results).to match("tig")
    end
    it "listoddsum(0123456789)" do
      results = listoddsum("0123456789")
      expect(results).to match("13579")
    end
    it "listoddsum(nil)" do
      results = listoddsum(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "listcat" do
    it "listcat(nil)" do
      results = listrev(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "listrev" do
    it "listrev(nil)" do
      results = listrev(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
