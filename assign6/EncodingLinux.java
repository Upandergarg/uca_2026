public class EncodingLinux {

    static String table =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // Base64 Encode
    static String encode(String s) {

        String bits = "";

        // Convert characters to 8-bit binary
        for (int i = 0; i < s.length(); i++) {

            int value = s.charAt(i);

            String binary = Integer.toBinaryString(value);

            while (binary.length() < 8) {
                binary = "0" + binary;
            }

            bits += binary;
        }

        String result = "";

        // Take 6 bits at a time
        for (int i = 0; i < bits.length(); i += 6) {

            String group = bits.substring(
                    i,
                    Math.min(i + 6, bits.length())
            );

            while (group.length() < 6) {
                group += "0";
            }

            int value = Integer.parseInt(group, 2);

            result += table.charAt(value);
        }

        // Padding
        int rem = s.length() % 3;

        if (rem == 1) {
            result += "==";
        }
        else if (rem == 2) {
            result += "=";
        }

        return result;
    }


    // Base64 Decode
    static String decode(String s) {

        String bits = "";

        // Convert Base64 characters to 6-bit binary
        for (int i = 0; i < s.length(); i++) {

            char c = s.charAt(i);

            // Ignore padding
            if (c == '=') {
                break;
            }

            int value = table.indexOf(c);

            String binary = Integer.toBinaryString(value);

            while (binary.length() < 6) {
                binary = "0" + binary;
            }

            bits += binary;
        }

        String result = "";

        // Take 8 bits at a time
        for (int i = 0; i + 7 < bits.length(); i += 8) {

            String group = bits.substring(i, i + 8);

            int value = Integer.parseInt(group, 2);

            result += (char) value;
        }

        return result;
    }


    public static void main(String[] args) {

        String original = "upiiiiiii";

        String encoded = encode(original);

        System.out.println("Original : " + original);
        System.out.println("Encoded  : " + encoded);
        System.out.println("Decoded  : " + decode(encoded));
    }
}