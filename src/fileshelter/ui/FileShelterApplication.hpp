/*
 * Copyright (C) 2016 Emeric Poupon
 *
 * This file is part of fileshelter.
 *
 * fileshelter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * fileshelter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with fileshelter.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <memory>
#include <string_view>
#include <Wt/WApplication.h>

namespace Wt::Dbo
{
	class Session;
}

namespace UserInterface
{

	class FileShelterApplication : public Wt::WApplication
	{
		public:
			FileShelterApplication(const Wt::WEnvironment& env);

			static std::unique_ptr<Wt::WApplication> create(const Wt::WEnvironment& env);
			static FileShelterApplication* instance();

		private:
			void initialize() override;
			void notify(const Wt::WEvent& event) override;

			void displayError(std::string_view error);
	};

#define FsApp FileShelterApplication::instance()

} // namespace UserInterface


