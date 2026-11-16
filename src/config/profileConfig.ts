import type { ProfileConfig } from "@/types/config";
import { withUserConfig } from "../utils/config-overlay.ts";

// Personal profile shown in the sidebar and feeds.
export const profileConfig: ProfileConfig = withUserConfig("profile", {
  avatar: "https://avatars.githubusercontent.com/u/357431303?v=4",
  name: "CagedBird404",
  bio: "记录 C++、计算机网络与操作系统的学习过程。",
  links: [
    {
      name: "GitHub",
      icon: "fa7-brands:github",
      url: "https://github.com/CagedBird404",
    },
  ],
});
